# -*- coding: utf-8 -*-
"""
Created on Tue Aug 15 19:35:33 2023

@author: george_howell
"""

from matplotlib import pyplot as plt
import numpy as np

"""
User Options
"""

writeToFile = True

# inputs
N = 1024
f = 100
fs = 48000
t = np.arange(0,N) * (1/fs)
fVec = np.arange(0,N)*(fs/N)

"""
Input Signal
"""

# create basic signal
x = np.sin(2*np.pi*f*t)

"""
FFT Signal
"""

# fft data
X = np.fft.fft(x)

# convert to db
Xdb = 20*np.log10(abs(X))

# interleave complex data
Xr = np.real(X)
Xi = np.imag(X)

# create interleaved complex data
Xint = np.empty((Xr.size + Xi.size,), dtype=Xr.dtype)
Xint[0::2] = Xr
Xint[1::2] = Xi

# save data to file
if writeToFile:
    np.savetxt('din.dat', x, fmt ='%.23f,')
    np.savetxt('fftRef.dat', Xint, fmt ='%.23f,')

"""
IFFT Signal
"""

# fft data
y = np.real(np.fft.ifft(X))

# save data to file
if writeToFile:
    np.savetxt('dout.dat', y, fmt ='%.23f,')

"""
Error
"""

err = np.sum(abs(y - x))
print("Error: %.20f" % err)


"""
Plot Data
"""
fig, (ax1, ax2) = plt.subplots(2,1)
fig.subplots_adjust(hspace=0.75)

# plot input and filtered signal
ax1.plot(t, x, label='input')
ax1.plot(t, y, label='output')
ax1.grid()
ax1.title.set_text('Input vs. Output')
ax1.set_xlabel('time [s]')
ax1.set_ylabel('amplitude')
leg = ax1.legend(loc='lower right')

# plot filter response
ax2.plot(fVec, Xdb)
ax2.grid()
ax2.title.set_text('FFT')
ax2.set_xlabel('freq [Hz]')
ax2.set_ylabel('maghnitude [dB]')
ax2.set_xlim(0,fs/2)
