; ====================
sr = 44100
kr = 441
ksmps = 100
nchnls = 2
; ====================

; =======================================
instr 1 ; (short atack, long release)
; =======================================
iamp = p5 * 30000
ifreq = cpspch(p4)
itable = 1

kamp linen 1.0, 0.02, p3, (0.8 * p3)
asig oscil iamp, ifreq, itable
aout = kamp * asig
outs aout, aout
; =======================================
endin
; =======================================
; =======================================
instr 2 ; (medium atack, short release)
; =======================================
iamp = p5 * 30000
ifreq = cpspch(p4)
itable = 2

kamp linen 1.0, 0.1, p3, (0.1 * p3)
asig oscil iamp, ifreq, itable
aout = kamp * asig
outs aout, aout
; =======================================
endin
; =======================================
; =======================================
instr 3 ; (long atack, long release)
; =======================================
 ;SOPRANO & ALTO 
iamp =p5 * 30000

i2 = (1/p4)+.5
i2 = int(i2)

i5 = .4
i9 = exp(1.5*log(p4/32767))

i14 = i9


k1 poscil 1.5, 2.7, 1  ;Vibrato: amp 1.5, 2.7 Hz, f1 
a1 linen 20,.1,p3,.08 
a2 oscil p4,p4,3 
a8 = p4+a2
a6 linseg -.03,.07,.03,.03,0,p3-.1,0 
a6 = a6+1.
a1 oscili a1,(a8+a2)*a6,3 
a7 = a2+i2
a3 linseg 0,.07,.1,.03,1.,p3-.008,1,.02,.1,.03,0 
a3 oscili a3,a7*a6,3 
ar pluck iamp*1.5, p4, p4, 3, 3, 0, 1 
arampsig=ar*.3+k1*(a1+a3)*p4*.09 
outs arampsig , arampsig 

endin
; =======================================
instr 4
; =======================================

          
iamp = p5 * 30000
ifreq = cpspch(p4)
itable = 1

kamp linen 0.9, 0.05, p3, (0.4 * p3)
kamp2 linen 0.7, (0.5*p3), p3, (0.4 * p3)
kamp3 linen 0.6, 0.1, p3, (0.5 * p3)
kamp4 linen 0.5, 0.02, p3, (0.6 * p3)
kamp5 linen 0.4, 0.2, p3, (0.8 * p3)
kamp6 linen 0.3, 0.3, p3, (0.7 * p3)
kamp7 linen 0.2, 0.4, p3, (0.6 * p3)
kamp8 linen 0.1, 0.5, p3, (0.5 * p3)
asig oscil iamp, ifreq, itable
asig2 oscil iamp, ifreq*2, itable
asig3 oscil iamp, ifreq*4, itable
asig4 oscil iamp, ifreq*8, itable
asig5 oscil iamp, ifreq*16, itable
asig6 oscil iamp, ifreq*32, itable
asig7 oscil iamp, ifreq*64, itable
asig8 oscil iamp, ifreq*128, itable
aout = (kamp* asig+kamp2* asig2+kamp3* asig3+kamp4* asig4+kamp5* asig5+kamp6* asig6+kamp7* asig7+kamp8* asig8)/8
outs aout, aout
endin

