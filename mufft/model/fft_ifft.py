# -*- coding: utf-8 -*-
"""
Created on Tue Aug 15 19:35:33 2023

@author: george_howell
"""

import numpy as np

# inputs
N = 16

# create basic signal
x = np.sin(np.linspace(0, 2*np.pi, N))

# fft data
X = np.fft.fft(x)

# interleave complex data
Xr = np.real(X)
Xi = np.imag(X)

Xint = np.empty((Xr.size + Xi.size,), dtype=Xr.dtype)
Xint[0::2] = Xr
Xint[1::2] = Xi

# save data to file
np.savetxt('din.dat', x, fmt ='%.23f,')
np.savetxt('doutRef.dat', Xint, fmt ='%.23f,')
