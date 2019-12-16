instr 1 ;SOPRANO & ALTO 
iamp =p4*.6

i2 = (1/p5)+.5
i2 = int(i2)

i5 = .4
i9 = exp(1.5*log(p5/32767))

i14 = i9
irvbgain=p10
iEGgain=p11
k1 poscil 1.5, 2.7, 1  ;Vibrato: amp 1.5, 2.7 Hz, f1 
a1 linen 20,.1,p3,.08 
a2 oscil p5,p5,3 
a8 = p5+a2
a6 linseg -.03,.07,.03,.03,0,p3-.1,0 
a6 = a6+1.a1 oscili 
a1,(a8+a2)*a6,3 
a7 = a2+i2a3 linseg 0,.07,.1,.03,1.,p3-.008,1,.02,.1,.03,0 
a3 oscili a3,a7*a6,3 
ar pluck iamp*1.5, p5, p5, 3, 3, 0, 1 
arampsig=ar*.3+k1*(a1+a3)*p5*.09 
outs arampsig * ibalance, arampsig * (1 - ibalance) 
garvbsig = garvbsig + arampsig * irvbgain
endin
