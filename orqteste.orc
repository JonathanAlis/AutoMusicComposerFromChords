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
iamp = p5 * 30000
ifreq = cpspch(p4)
itable = 3

kamp linen 1.0, (0.3 *p3), p3, (0.5 * p3)
asig oscil iamp, ifreq, itable
aout = kamp * asig
outs aout, aout
; =======================================
endin
; =======================================
; =======================================
instr 4 ; (short atack, medium release)
;=============================
;inst st dur amp pch plksize(%) fbfac pickupPos(%) pluckPos(%)

; Initializations

  afwav   init 0

  abkwav  init 0

  abkdout init 0

  afwdout init 0 

  

  iEstr	 = 1/cpspch(6.04)

  ifqc   = cpspch(p4)

  idlt   = 1/(ifqc)		;note:delay time=2x length of string (time to traverse it)

  ipluck = .5*idlt * p6 * ifqc/cpspch(8.02)

  ifbfac = p7  			;feedback factor

  ibrightness = p10*exp(p6*log(2))/2 ;(exponentialy scaled) additive noise to add hi freq content

  ivibRate = p11	;vibrato rate

  ivibDepth pow 2,p12/12

  ivibDepth = idlt-1/(ivibDepth*ifqc)	;vibrato depth, +,- ivibDepth semitones

  ivibStDly = p13 ;vibrato start delay (secs)

  

  ;termination impedance model

  if0 = 10000 ;cutoff freq of LPF due to mech. impedance at the nut (2kHz-10kHz)

  iA0 = p7  ;damping parameter of nut impedance

  ialpha = cos(2*3.14159265*if0*1/sr)

  ia0 = .3*iA0/(2*(1-ialpha))  ; FIR LPF model of nut impedance,  H(z)=a0+a1z^-1+a0z^-2

  ia1 = iA0-2*ia0

  ;NOTE each filter pass adds a sampling period delay,so subtract 1/sr from tap time to compensate



  ;determine (in crude fashion) which string is being played

 ; icurStr = (ifqc > cpspch(6.04) ? 2 : 1)

 ; icurStr = (ifqc > cpspch(6.09) ? 3 : icurStr)

 ; icurStr = (ifqc > cpspch(7.02) ? 4 : icurStr)

 ; icurStr = (ifqc > cpspch(7.07) ? 5 : icurStr)

 ; icurStr = (ifqc > cpspch(7.11) ? 6 : icurStr)

 



  ipupos = p8*idlt/2; pick up position (in % of low E string length)

  ippos  = p9*idlt/2; pluck position (in % of low E string length)

  

  isegF = 1/sr

  isegF2 = ipluck

  iplkdelF = (ipluck/2 > ippos ? 0 : ippos-ipluck/2)

  isegB = 1/sr

  isegB2 = ipluck

  iplkdelB = (ipluck/2 > idlt/2-ippos ? 0 : idlt/2-ippos-ipluck/2)



;EXCITATION SIGNAL GENERATION

;the two excitation signals are fed into the fwd delay represent the 1st and 2nd 

; reflections off of the left boundary, and two accelerations fed into the bkwd delay 

; represent the the 1st and 2nd reflections off of the right boundary.

;Likewise for the backward traveling acceleration waves, only they encouter the 

; terminationsin the opposite order.

  ipw = 1;

  ipamp = p5*ipluck;4/ipluck



aenvstrf linseg 0,isegF,-ipamp/2,isegF2,0

  adel1	delayr idlt

  aenvstrf1 deltapi iplkdelF        ;initial forward traveling wave (pluck to bridge)

  aenvstrf2 deltapi iplkdelB+idlt/2 ;first forward traveling reflection (nut to bridge) 

	delayw aenvstrf



; inject noise for attack time string fret contact, and pre pluck vibrations against pick 

anoiz rand	ibrightness

aenvstrf1 = aenvstrf1 + anoiz*aenvstrf1

aenvstrf2 = aenvstrf2 + anoiz*aenvstrf2



; filter to account for losses along loop path

  aenvstrf2	filter2  aenvstrf2, 3, 0, ia0,ia1,ia0 

; combine into one signal (flip refl wave's phase)

  aenvstrf = aenvstrf1-aenvstrf2



; initial backward excitation wave  

  aenvstrb linseg 0,isegB,-ipamp/2,isegB2,0  

  adel2	delayr idlt

  aenvstrb1 deltapi iplkdelB        ; initial bdwd traveling wave (pluck to nut)

  aenvstrb2 deltapi idlt/2+iplkdelF ;first forward traveling reflection (nut to bridge) 

	delayw aenvstrb



; initial bdwd traveling wave (pluck to nut)

;  aenvstrb1	delay	aenvstrb,  iplkdelB

; first bkwd traveling reflection (bridge to nut)

;  aenvstrb2	delay	aenvstrb, idlt/2+iplkdelF

  

; inject noise

aenvstrb1 = aenvstrb1 + anoiz*aenvstrb1

aenvstrb2 = aenvstrb2 + anoiz*aenvstrb2

    

  

; filter to account for losses along loop path

  aenvstrb2	filter2  aenvstrb2, 3, 0, ia0,ia1,ia0

; combine into one signal (flip refl wave's phase)

  aenvstrb	=	aenvstrb1-aenvstrb2



; low pass to band limit initial accel signals to be < 1/2 the sampling freq

  ainputf  tone  aenvstrf,sr*.9/2

  ainputb  tone  aenvstrb,sr*.9/2

; additional lowpass filtering for pluck shaping\

;Note, it would be more efficient to combine stages into a single filter

  ainputf  tone  ainputf,sr*.9/2

  ainputb  tone  ainputb,sr*.9/2



; Vibrato generator

avib oscili ivibDepth, ivibRate,1

avibdl		delayr		ivibStDly*1.1+.001

avibrato	deltapi	ivibStDly

			delayw		avib



; Dual Delay line, 

; NOTE: delay length longer than needed by a bit so that the output at t=idlt will be interpolated properly        

; fwd 		delay line

  afd  		delayr (idlt+ivibDepth)*1.1		;forward traveling wave delay line

  afwav  	deltapi ipupos    	;output tap point for fwd traveling wave

  afwdout	deltapi idlt-1/sr + avibrato	;output at end of fwd delay (left string boundary)

  afwdout	filter2  afwdout, 3, 0, ia0,ia1,ia0  ;lpf/attn due to reflection impedance		

  			delayw  ainputf + afwdout*ifbfac*ifbfac



; bkwd delay line

  abkwd  	delayr (idlt+ivibDepth)*1.1          	;backward trav wave delay line

  abkwav  	deltapi idlt/2-ipupos		;output tap point for bkwd traveling wave

;  abkterm	deltapi	idlt/2				;output at the left boundary

  abkdout	deltapi idlt -1/sr + avibrato	;output at end of bkwd delay (right string boundary)

  abkdout	filter2  abkdout, 3, 0, ia0,ia1,ia0  	

  			delayw  ainputb + abkdout*ifbfac*ifbfac

;resonant body filter model, from Cuzzucoli and Lombardo

;IIR filter derived via bilinear transform method

;the theoretical resonances resulting from circuit model should be:

;resonance due to the air volume + soundhole = 110Hz (strongest)

;resonance due to the top plate = 220Hz

;resonance due to the inclusion of the back plate = 400Hz (weakest)

aresbod filter2 (afwdout + abkdout), 5,4, .000000000005398681501844749,.00000000000001421085471520200,-.00000000001076383426834582,-00000000000001110223024625157,.000000000005392353230604385,-3.990098622573566,5.974971737738533,-3.979630684599723,.9947612723736902

           outs 1500*(afwav+abkwav+aresbod*.000000000000000000003),1500*(afwav+abkwav+aresbod*.000000000000000000003);

           endin

;************************************************************************

;1D String Physical Model

; slightly modified to be low string model: 

; More pluck shape smoothing via initial filtering.

; Increased resonant body filter gain

;

