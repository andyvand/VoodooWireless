/System/Library/Extensions/VoodooWireless.kext/Contents/MacOS/VoodooWireless:
(__TEXT,__text) section
__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf:
00000000	pushl	%ebp
00000001	movl	$0x00000006,%eax
00000006	movl	%esp,%ebp
00000008	leave
00000009	ret
__ZN17IO80211Controller25monitorPacketHeaderLengthEP16IO80211Interface:
0000000a	pushl	%ebp
0000000b	xorl	%eax,%eax
0000000d	movl	%esp,%ebp
0000000f	leave
00000010	ret
00000011	nop
__ZN17IO80211Controller10monitorDLTEP16IO80211Interface:
00000012	pushl	%ebp
00000013	xorl	%eax,%eax
00000015	movl	%esp,%ebp
00000017	leave
00000018	ret
00000019	nop
__ZN17IO80211Controller7stopDMAEv:
0000001a	pushl	%ebp
0000001b	movl	$0x00000066,%eax
00000020	movl	%esp,%ebp
00000022	leave
00000023	ret
__ZN17IO80211Controller24hardwareOutputQueueDepthEP16IO80211Interface:
00000024	pushl	%ebp
00000025	xorl	%eax,%eax
00000027	movl	%esp,%ebp
00000029	leave
0000002a	ret
0000002b	nop
__ZN17IO80211Controller27performCountryCodeOperationEP16IO80211Interface20IO80211CountryCodeOp:
0000002c	pushl	%ebp
0000002d	movl	$0x00000066,%eax
00000032	movl	%esp,%ebp
00000034	leave
00000035	ret
__ZN17IO80211Controller21useAppleRSNSupplicantEP16IO80211Interface:
00000036	pushl	%ebp
00000037	movl	$0x00000001,%eax
0000003c	movl	%esp,%ebp
0000003e	leave
0000003f	ret
__ZN17IO80211Controller13enableFeatureE18IO80211FeatureCodePv:
00000040	pushl	%ebp
00000041	movl	$0x00000066,%eax
00000046	movl	%esp,%ebp
00000048	leave
00000049	ret
__ZN20VoodooWirelessDeviceC2EPK11OSMetaClass:
0000004a	pushl	%ebp
0000004b	movl	%esp,%ebp
0000004d	pushl	%ebx
0000004e	subl	$0x14,%esp
00000051	movl	0x08(%ebp),%ebx
00000054	movl	0x0c(%ebp),%eax
00000057	movl	%ebx,(%esp)
0000005a	movl	%eax,0x04(%esp)
0000005e	calll	__ZN17IO80211ControllerC2EPK11OSMetaClass
00000063	movl	%ebx,%eax
00000065	movl	$__ZTV20VoodooWirelessDevice,(%ebx)
0000006b	addl	$0x14,%esp
0000006e	popl	%ebx
0000006f	leave
00000070	ret
00000071	nop
__ZN20VoodooWirelessDeviceC1EPK11OSMetaClass:
00000072	pushl	%ebp
00000073	movl	%esp,%ebp
00000075	pushl	%ebx
00000076	subl	$0x14,%esp
00000079	movl	0x08(%ebp),%ebx
0000007c	movl	0x0c(%ebp),%eax
0000007f	movl	%ebx,(%esp)
00000082	movl	%eax,0x04(%esp)
00000086	calll	__ZN17IO80211ControllerC2EPK11OSMetaClass
0000008b	movl	%ebx,%eax
0000008d	movl	$__ZTV20VoodooWirelessDevice,(%ebx)
00000093	addl	$0x14,%esp
00000096	popl	%ebx
00000097	leave
00000098	ret
00000099	nop
__ZN20VoodooWirelessDeviceD2Ev:
0000009a	pushl	%ebp
0000009b	movl	%esp,%ebp
0000009d	pushl	%ebx
0000009e	subl	$0x14,%esp
000000a1	movl	0x08(%ebp),%ebx
000000a4	movl	$__ZTV20VoodooWirelessDevice,(%ebx)
000000aa	movl	%ebx,(%esp)
000000ad	calll	__ZN17IO80211ControllerD2Ev
000000b2	movl	%ebx,%eax
000000b4	addl	$0x14,%esp
000000b7	popl	%ebx
000000b8	leave
000000b9	ret
__ZN20VoodooWirelessDeviceD1Ev:
000000ba	pushl	%ebp
000000bb	movl	%esp,%ebp
000000bd	pushl	%ebx
000000be	subl	$0x14,%esp
000000c1	movl	0x08(%ebp),%ebx
000000c4	movl	$__ZTV20VoodooWirelessDevice,(%ebx)
000000ca	movl	%ebx,(%esp)
000000cd	calll	__ZN17IO80211ControllerD2Ev
000000d2	movl	%ebx,%eax
000000d4	addl	$0x14,%esp
000000d7	popl	%ebx
000000d8	leave
000000d9	ret
__ZN20VoodooWirelessDeviceD0Ev:
000000da	pushl	%ebp
000000db	movl	%esp,%ebp
000000dd	pushl	%ebx
000000de	subl	$0x14,%esp
000000e1	movl	0x08(%ebp),%ebx
000000e4	movl	$__ZTV20VoodooWirelessDevice,(%ebx)
000000ea	movl	%ebx,(%esp)
000000ed	calll	__ZN17IO80211ControllerD2Ev
000000f2	movl	%ebx,(%esp)
000000f5	movl	$0x000006bc,0x04(%esp)
000000fd	calll	__ZN8OSObjectdlEPvm
00000102	movl	%ebx,%eax
00000104	addl	$0x14,%esp
00000107	popl	%ebx
00000108	leave
00000109	ret
__ZNK20VoodooWirelessDevice12getMetaClassEv:
0000010a	pushl	%ebp
0000010b	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,%eax
00000110	movl	%esp,%ebp
00000112	leave
00000113	ret
__ZN20VoodooWirelessDevice9MetaClassC1Ev:
00000114	pushl	%ebp
00000115	movl	%esp,%ebp
00000117	pushl	%ebx
00000118	subl	$0x14,%esp
0000011b	movl	0x08(%ebp),%ebx
0000011e	movl	__ZN20VoodooWirelessDevice10superClassE,%eax
00000123	movl	$0x000006bc,0x0c(%esp)
0000012b	movl	$0x0000382c,0x04(%esp)
00000133	movl	%ebx,(%esp)
00000136	movl	%eax,0x08(%esp)
0000013a	calll	__ZN11OSMetaClassC2EPKcPKS_j
0000013f	movl	%ebx,%eax
00000141	movl	$__ZTVN20VoodooWirelessDevice9MetaClassE,(%ebx)
00000147	addl	$0x14,%esp
0000014a	popl	%ebx
0000014b	leave
0000014c	ret
0000014d	nop
__ZN20VoodooWirelessDevice9MetaClassC2Ev:
0000014e	pushl	%ebp
0000014f	movl	%esp,%ebp
00000151	pushl	%ebx
00000152	subl	$0x14,%esp
00000155	movl	0x08(%ebp),%ebx
00000158	movl	__ZN20VoodooWirelessDevice10superClassE,%eax
0000015d	movl	$0x000006bc,0x0c(%esp)
00000165	movl	$0x0000382c,0x04(%esp)
0000016d	movl	%ebx,(%esp)
00000170	movl	%eax,0x08(%esp)
00000174	calll	__ZN11OSMetaClassC2EPKcPKS_j
00000179	movl	%ebx,%eax
0000017b	movl	$__ZTVN20VoodooWirelessDevice9MetaClassE,(%ebx)
00000181	addl	$0x14,%esp
00000184	popl	%ebx
00000185	leave
00000186	ret
00000187	nop
__ZN20VoodooWirelessDeviceC1Ev:
00000188	pushl	%ebp
00000189	movl	%esp,%ebp
0000018b	pushl	%ebx
0000018c	subl	$0x14,%esp
0000018f	movl	0x08(%ebp),%ebx
00000192	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,0x04(%esp)
0000019a	movl	%ebx,(%esp)
0000019d	calll	__ZN17IO80211ControllerC2EPK11OSMetaClass
000001a2	movl	$__ZTV20VoodooWirelessDevice,(%ebx)
000001a8	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
000001af	calll	__ZNK11OSMetaClass19instanceConstructedEv
000001b4	movl	%ebx,%eax
000001b6	addl	$0x14,%esp
000001b9	popl	%ebx
000001ba	leave
000001bb	ret
__ZNK20VoodooWirelessDevice9MetaClass5allocEv:
000001bc	pushl	%ebp
000001bd	movl	%esp,%ebp
000001bf	pushl	%ebx
000001c0	subl	$0x14,%esp
000001c3	movl	$0x000006bc,(%esp)
000001ca	calll	__ZN8OSObjectnwEm
000001cf	movl	%eax,%ebx
000001d1	xorl	%eax,%eax
000001d3	testl	%ebx,%ebx
000001d5	je	0x000001e1
000001d7	movl	%ebx,(%esp)
000001da	calll	__ZN20VoodooWirelessDeviceC1Ev
000001df	movl	%ebx,%eax
000001e1	addl	$0x14,%esp
000001e4	popl	%ebx
000001e5	leave
000001e6	ret
000001e7	nop
__ZN20VoodooWirelessDeviceC2Ev:
000001e8	pushl	%ebp
000001e9	movl	%esp,%ebp
000001eb	pushl	%ebx
000001ec	subl	$0x14,%esp
000001ef	movl	0x08(%ebp),%ebx
000001f2	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,0x04(%esp)
000001fa	movl	%ebx,(%esp)
000001fd	calll	__ZN17IO80211ControllerC2EPK11OSMetaClass
00000202	movl	$__ZTV20VoodooWirelessDevice,(%ebx)
00000208	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
0000020f	calll	__ZNK11OSMetaClass19instanceConstructedEv
00000214	movl	%ebx,%eax
00000216	addl	$0x14,%esp
00000219	popl	%ebx
0000021a	leave
0000021b	ret
__ZN20VoodooWirelessDevice5startEP9IOService:
0000021c	pushl	%ebp
0000021d	movl	%esp,%ebp
0000021f	pushl	%esi
00000220	pushl	%ebx
00000221	subl	$0x20,%esp
00000224	movl	0x08(%ebp),%ebx
00000227	movl	0x0c(%ebp),%esi
0000022a	movl	%ebx,(%esp)
0000022d	movl	%esi,0x04(%esp)
00000231	call	*__ZTV17IO80211Controller+0x000002cc
00000237	testb	%al,%al
00000239	jel	0x000003eb
0000023f	calll	_IOLockAlloc
00000244	testl	%eax,%eax
00000246	movl	%eax,0x00000464(%ebx)
0000024c	jel	0x000003eb
00000252	movl	(%ebx),%eax
00000254	movl	%ebx,(%esp)
00000257	call	*0x00000334(%eax)
0000025d	movl	__ZN15IO80211WorkLoop9metaClassE,%edx
00000263	movl	%edx,0x04(%esp)
00000267	movl	%eax,(%esp)
0000026a	calll	__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass
0000026f	movl	%eax,0x0000047c(%ebx)
00000275	movl	(%eax),%edx
00000277	movl	%eax,(%esp)
0000027a	call	*0x18(%edx)
0000027d	movl	0x0000047c(%ebx),%eax
00000283	movl	%eax,(%esp)
00000286	calll	__ZN13IOCommandPool12withWorkLoopEP10IOWorkLoop
0000028b	movl	%eax,0x00000480(%ebx)
00000291	movl	$0x00000020,(%esp)
00000298	calll	__ZN7OSArray12withCapacityEj
0000029d	movl	%eax,0x00000484(%ebx)
000002a3	movl	(%ebx),%eax
000002a5	movl	%esi,0x04(%esp)
000002a9	movl	%ebx,(%esp)
000002ac	call	*0x00000730(%eax)
000002b2	testl	%eax,%eax
000002b4	je	0x000002c2
000002b6	movl	$0x00003848,(%esp)
000002bd	jmpl	0x000003ac
000002c2	movl	(%ebx),%eax
000002c4	leal	0x000002a0(%ebx),%edx
000002ca	orl	$0x01,0x00000460(%ebx)
000002d1	movl	%edx,0x04(%esp)
000002d5	movl	%ebx,(%esp)
000002d8	call	*0x00000750(%eax)
000002de	movl	$0x00000001,(%esp)
000002e5	calll	__ZN12OSDictionary12withCapacityEj
000002ea	movl	0x000002bc(%ebx),%ecx
000002f0	movl	%eax,%esi
000002f2	movl	%ecx,%eax
000002f4	andl	$0x04,%eax
000002f7	cmpl	$0x01,%eax
000002fa	sbbl	%edx,%edx
000002fc	notl	%edx
000002fe	andl	$0x00a7d8c0,%edx
00000304	testb	$0x02,%cl
00000307	jne	0x0000030e
00000309	testb	$0x08,%cl
0000030c	je	0x00000313
0000030e	movl	$0x0337f980,%edx
00000313	andl	$0x10,%ecx
00000316	movl	$0x11e1a300,%eax
0000031b	cmovnel	%eax,%edx
0000031e	movl	%edx,0x04(%esp)
00000322	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x14(%esp)
0000032a	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x10(%esp)
00000332	movl	$0x00200000,0x0c(%esp)
0000033a	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00000342	movl	$0x00000080,(%esp)
00000349	calll	__ZN15IONetworkMedium6mediumEmymmPKc
0000034e	movl	%eax,0x00000470(%ebx)
00000354	movl	%eax,0x04(%esp)
00000358	movl	%esi,(%esp)
0000035b	calll	__ZN15IONetworkMedium9addMediumEP12OSDictionaryPKS_
00000360	movl	(%ebx),%eax
00000362	movl	%esi,0x04(%esp)
00000366	movl	%ebx,(%esp)
00000369	call	*0x00000534(%eax)
0000036f	movl	(%ebx),%edx
00000371	movl	0x00000470(%ebx),%eax
00000377	movl	%ebx,(%esp)
0000037a	movl	%eax,0x04(%esp)
0000037e	call	*0x00000538(%edx)
00000384	movl	(%ebx),%edx
00000386	leal	0x00000474(%ebx),%eax
0000038c	movl	$0x00000001,0x08(%esp)
00000394	movl	%eax,0x04(%esp)
00000398	movl	%ebx,(%esp)
0000039b	call	*0x0000055c(%edx)
000003a1	testb	%al,%al
000003a3	jne	0x000003b3
000003a5	movl	$0x00003880,(%esp)
000003ac	calll	_IOLog
000003b1	jmp	0x000003eb
000003b3	movl	$0x0000001e,0x08(%esp)
000003bb	movl	$0x00000069,0x04(%esp)
000003c3	movl	0x00000474(%ebx),%eax
000003c9	movl	%eax,(%esp)
000003cc	calll	__ZN16IO80211Interface9bpfAttachEmm
000003d1	movl	(%ebx),%eax
000003d3	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x04(%esp)
000003db	movl	%ebx,(%esp)
000003de	call	*0x000002c4(%eax)
000003e4	movl	$0x00000001,%eax
000003e9	jmp	0x000003ed
000003eb	xorl	%eax,%eax
000003ed	addl	$0x20,%esp
000003f0	popl	%ebx
000003f1	popl	%esi
000003f2	leave
000003f3	ret
__ZN20VoodooWirelessDevice4stopEP9IOService:
000003f4	pushl	%ebp
000003f5	movl	%esp,%ebp
000003f7	pushl	%esi
000003f8	pushl	%ebx
000003f9	subl	$0x10,%esp
000003fc	movl	0x08(%ebp),%ebx
000003ff	movl	0x0c(%ebp),%esi
00000402	movl	(%ebx),%eax
00000404	movl	%esi,0x04(%esp)
00000408	movl	%ebx,(%esp)
0000040b	call	*0x00000734(%eax)
00000411	movl	0x00000464(%ebx),%eax
00000417	andl	$0xfe,0x00000460(%ebx)
0000041e	testl	%eax,%eax
00000420	je	0x0000042a
00000422	movl	%eax,(%esp)
00000425	calll	_IOLockFree
0000042a	movl	0x00000484(%ebx),%edx
00000430	testl	%edx,%edx
00000432	je	0x00000446
00000434	movl	(%edx),%eax
00000436	movl	%edx,(%esp)
00000439	call	*0x1c(%eax)
0000043c	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000484(%ebx)
00000446	movl	0x00000478(%ebx),%edx
0000044c	testl	%edx,%edx
0000044e	je	0x00000462
00000450	movl	(%edx),%eax
00000452	movl	%edx,(%esp)
00000455	call	*0x1c(%eax)
00000458	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000478(%ebx)
00000462	movl	0x00000474(%ebx),%edx
00000468	testl	%edx,%edx
0000046a	je	0x0000047e
0000046c	movl	(%edx),%eax
0000046e	movl	%edx,(%esp)
00000471	call	*0x1c(%eax)
00000474	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000474(%ebx)
0000047e	movl	0x00000470(%ebx),%edx
00000484	testl	%edx,%edx
00000486	je	0x0000049a
00000488	movl	(%edx),%eax
0000048a	movl	%edx,(%esp)
0000048d	call	*0x1c(%eax)
00000490	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000470(%ebx)
0000049a	movl	0x00000480(%ebx),%edx
000004a0	testl	%edx,%edx
000004a2	je	0x000004b6
000004a4	movl	(%edx),%eax
000004a6	movl	%edx,(%esp)
000004a9	call	*0x1c(%eax)
000004ac	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000480(%ebx)
000004b6	movl	0x0000047c(%ebx),%edx
000004bc	testl	%edx,%edx
000004be	je	0x000004d2
000004c0	movl	(%edx),%eax
000004c2	movl	%edx,(%esp)
000004c5	call	*0x1c(%eax)
000004c8	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0000047c(%ebx)
000004d2	movl	%esi,0x0c(%ebp)
000004d5	movl	__ZTV17IO80211Controller+0x000002d0,%ecx
000004db	movl	%ebx,0x08(%ebp)
000004de	addl	$0x10,%esp
000004e1	popl	%ebx
000004e2	popl	%esi
000004e3	leave
000004e4	jmp	*%ecx
__ZN20VoodooWirelessDevice23registerWithPolicyMakerEP9IOService:
000004e6	pushl	%ebp
000004e7	movl	%esp,%ebp
000004e9	subl	$0x18,%esp
000004ec	movl	0x0c(%ebp),%edx
000004ef	movl	0x08(%ebp),%eax
000004f2	movl	(%edx),%ecx
000004f4	movl	$0x00000002,0x0c(%esp)
000004fc	movl	$__ZZN20VoodooWirelessDevice23registerWithPolicyMakerEP9IOServiceE15powerStateArray,0x08(%esp)
00000504	movl	%eax,0x04(%esp)
00000508	movl	%edx,(%esp)
0000050b	call	*0x000003fc(%ecx)
00000511	leave
00000512	ret
00000513	nop
__ZN20VoodooWirelessDevice14enqueueCommandEjPvS0_:
00000514	pushl	%ebp
00000515	movl	%esp,%ebp
00000517	subl	$0x18,%esp
0000051a	movl	0x14(%ebp),%eax
0000051d	movl	%eax,0x08(%esp)
00000521	movl	0x10(%ebp),%eax
00000524	movl	%eax,0x04(%esp)
00000528	movl	0x0c(%ebp),%eax
0000052b	movl	%eax,(%esp)
0000052e	calll	__ZN21VoodooWirelessCommand8withTypeENS_11CommandTypeEPvS1_
00000533	movl	%eax,%ecx
00000535	movl	$0xe00002bc,%eax
0000053a	testl	%ecx,%ecx
0000053c	je	0x00000558
0000053e	movl	0x08(%ebp),%edx
00000541	movl	0x00000480(%edx),%eax
00000547	movl	(%eax),%edx
00000549	movl	%eax,(%esp)
0000054c	movl	%ecx,0x04(%esp)
00000550	call	*0x000000a0(%edx)
00000556	xorl	%eax,%eax
00000558	leave
00000559	ret
__ZN20VoodooWirelessDevice5todBmEi:
0000055a	pushl	%ebp
0000055b	movl	%esp,%ebp
0000055d	movl	0x08(%ebp),%eax
00000560	movl	0x0c(%ebp),%edx
00000563	movl	0x0000044c(%eax),%eax
00000569	cmpl	$0x01,%eax
0000056c	je	0x00000575
0000056e	cmpl	$0x02,%eax
00000571	jne	0x000005b1
00000573	jmp	0x00000590
00000575	leal	0x88(%edx),%eax
00000578	movl	$0xffffff88,%edx
0000057d	cmpl	$0x87,%eax
00000580	jle	0x000005b1
00000582	cmpl	$0xec,%eax
00000585	movl	%eax,%edx
00000587	jle	0x000005b1
00000589	movl	$0xffffffec,%edx
0000058e	jmp	0x000005b1
00000590	leal	(%edx,%edx,4),%eax
00000593	movl	$0xffffff88,%edx
00000598	leal	0xffffff88(,%eax,4),%eax
0000059f	cmpl	$0x87,%eax
000005a2	jle	0x000005b1
000005a4	movl	%eax,%edx
000005a6	cmpl	$0xed,%eax
000005a9	movl	$0xffffffec,%eax
000005ae	cmovgel	%eax,%edx
000005b1	leave
000005b2	movl	%edx,%eax
000005b4	ret
000005b5	nop
__ZN20VoodooWirelessDevice12workerThreadEPv:
000005b6	pushl	%ebp
000005b7	movl	%esp,%ebp
000005b9	pushl	%edi
000005ba	pushl	%esi
000005bb	pushl	%ebx
000005bc	subl	$0x1c,%esp
000005bf	movl	0x08(%ebp),%edi
000005c2	movl	0x00000480(%edi),%eax
000005c8	movl	(%eax),%edx
000005ca	movl	$0x00000001,0x04(%esp)
000005d2	movl	%eax,(%esp)
000005d5	call	*0x0000009c(%edx)
000005db	movl	__ZN21VoodooWirelessCommand9metaClassE,%edx
000005e1	movl	%edx,0x04(%esp)
000005e5	movl	%eax,(%esp)
000005e8	calll	__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass
000005ed	cmpl	$0x06,0x14(%eax)
000005f1	movl	%eax,%ebx
000005f3	jal	0x00000706
000005f9	movl	0x14(%eax),%eax
000005fc	jmp	*0x000034fc(,%eax,4)
00000603	movl	$0x00000001,%esi
00000608	jmpl	0x00000708
0000060d	movl	(%edi),%eax
0000060f	movl	%edi,(%esp)
00000612	call	*0x00000738(%eax)
00000618	testl	%eax,%eax
0000061a	je	0x00000625
0000061c	movl	$0x000038b8,(%esp)
00000623	jmp	0x00000644
00000625	orl	$0x02,0x00000460(%edi)
0000062c	jmp	0x00000655
0000062e	movl	(%edi),%eax
00000630	movl	%edi,(%esp)
00000633	call	*0x0000073c(%eax)
00000639	testl	%eax,%eax
0000063b	je	0x0000064e
0000063d	movl	$0x000038ec,(%esp)
00000644	calll	_IOLog
00000649	jmpl	0x00000706
0000064e	andl	$0xfd,0x00000460(%edi)
00000655	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
0000065d	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00000665	movl	$0x00000001,0x04(%esp)
0000066d	movl	0x00000474(%edi),%eax
00000673	movl	%eax,(%esp)
00000676	calll	__ZN16IO80211Interface11postMessageEmPvm
0000067b	jmpl	0x00000706
00000680	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000488(%edi)
0000068a	movl	0x1c(%ebx),%eax
0000068d	movl	(%edi),%edx
0000068f	movl	%eax,0x08(%esp)
00000693	movl	0x18(%ebx),%eax
00000696	movl	%edi,(%esp)
00000699	movl	%eax,0x04(%esp)
0000069d	call	*0x00000740(%edx)
000006a3	testl	%eax,%eax
000006a5	jne	0x00000706
000006a7	movl	0x00000484(%edi),%eax
000006ad	movl	(%eax),%edx
000006af	movl	%eax,(%esp)
000006b2	call	*0x000000b4(%edx)
000006b8	orl	$0x08,0x00000460(%edi)
000006bf	jmp	0x00000706
000006c1	movl	(%edi),%eax
000006c3	movl	%edi,(%esp)
000006c6	call	*0x00000744(%eax)
000006cc	andl	$0xf7,0x00000460(%edi)
000006d3	jmp	0x00000706
000006d5	movl	(%edi),%eax
000006d7	movl	0x18(%ebx),%edx
000006da	movl	%edi,(%esp)
000006dd	movl	%edx,0x04(%esp)
000006e1	call	*0x00000748(%eax)
000006e7	testl	%eax,%eax
000006e9	jne	0x00000706
000006eb	orl	$0x10,0x00000460(%edi)
000006f2	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%edi)
000006f9	jmp	0x00000706
000006fb	movl	(%edi),%eax
000006fd	movl	%edi,(%esp)
00000700	call	*0x0000074c(%eax)
00000706	xorl	%esi,%esi
00000708	movl	(%ebx),%eax
0000070a	movl	%ebx,(%esp)
0000070d	call	*0x1c(%eax)
00000710	movl	%esi,%eax
00000712	testb	%al,%al
00000714	jel	0x000005c2
0000071a	addl	$0x1c,%esp
0000071d	popl	%ebx
0000071e	popl	%esi
0000071f	popl	%edi
00000720	leave
00000721	ret
__ZN20VoodooWirelessDevice6enableEP18IONetworkInterface:
00000722	pushl	%ebp
00000723	movl	%esp,%ebp
00000725	pushl	%ebx
00000726	subl	$__ZN17IO80211Controller24hardwareOutputQueueDepthEP16IO80211Interface,%esp
00000729	movl	0x08(%ebp),%ebx
0000072c	movl	0x00000464(%ebx),%eax
00000732	movl	%eax,(%esp)
00000735	calll	_IOLockLock
0000073a	movl	0x00000460(%ebx),%eax
00000740	testb	$0x04,%al
00000742	jnel	0x00000819
00000748	testb	$0x01,%al
0000074a	jel	0x00000819
00000750	testb	$0x02,%al
00000752	jne	0x00000794
00000754	movl	(%ebx),%eax
00000756	movl	%ebx,(%esp)
00000759	call	*0x00000738(%eax)
0000075f	testl	%eax,%eax
00000761	jnel	0x00000819
00000767	orl	$0x02,0x00000460(%ebx)
0000076e	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
00000776	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
0000077e	movl	$0x00000001,0x04(%esp)
00000786	movl	0x00000474(%ebx),%eax
0000078c	movl	%eax,(%esp)
0000078f	calll	__ZN16IO80211Interface11postMessageEmPvm
00000794	movl	(%ebx),%eax
00000796	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x14(%esp)
0000079e	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
000007a6	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x10(%esp)
000007ae	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
000007b6	movl	$0x00000001,0x04(%esp)
000007be	movl	%ebx,(%esp)
000007c1	call	*0x0000053c(%eax)
000007c7	movl	0x00000474(%ebx),%eax
000007cd	movl	(%eax),%edx
000007cf	movl	$0x00000001,0x04(%esp)
000007d7	movl	%eax,(%esp)
000007da	call	*0x000005d4(%edx)
000007e0	movl	(%ebx),%eax
000007e2	movl	%ebx,(%esp)
000007e5	call	*0x00000508(%eax)
000007eb	movl	0x0000045c(%ebx),%edx
000007f1	movl	(%eax),%ecx
000007f3	movl	%edx,0x04(%esp)
000007f7	movl	%eax,(%esp)
000007fa	call	*0x000000b0(%ecx)
00000800	movl	0x00000464(%ebx),%eax
00000806	orl	$0x04,0x00000460(%ebx)
0000080d	movl	%eax,(%esp)
00000810	calll	_IOLockUnlock
00000815	xorl	%eax,%eax
00000817	jmp	0x00000838
00000819	movl	$0x00003920,(%esp)
00000820	calll	_IOLog
00000825	movl	0x00000464(%ebx),%eax
0000082b	movl	%eax,(%esp)
0000082e	calll	_IOLockUnlock
00000833	movl	$0xe00002bc,%eax
00000838	addl	$__ZN17IO80211Controller24hardwareOutputQueueDepthEP16IO80211Interface,%esp
0000083b	popl	%ebx
0000083c	leave
0000083d	ret
__ZN20VoodooWirelessDevice7disableEP18IONetworkInterface:
0000083e	pushl	%ebp
0000083f	movl	%esp,%ebp
00000841	pushl	%ebx
00000842	subl	$0x14,%esp
00000845	movl	0x08(%ebp),%ebx
00000848	movl	0x00000464(%ebx),%eax
0000084e	movl	%eax,(%esp)
00000851	calll	_IOLockLock
00000856	testb	$0x04,0x00000460(%ebx)
0000085d	jel	0x0000090f
00000863	movl	0x00000474(%ebx),%eax
00000869	movl	(%eax),%edx
0000086b	movl	$0x00000001,0x04(%esp)
00000873	movl	%eax,(%esp)
00000876	call	*0x000005d4(%edx)
0000087c	movl	(%ebx),%eax
0000087e	movl	%ebx,(%esp)
00000881	call	*0x00000508(%eax)
00000887	movl	(%eax),%edx
00000889	movl	%eax,(%esp)
0000088c	call	*0x000000a4(%edx)
00000892	movl	(%ebx),%eax
00000894	movl	%ebx,(%esp)
00000897	call	*0x00000508(%eax)
0000089d	movl	(%eax),%edx
0000089f	movl	%eax,(%esp)
000008a2	call	*0x000000ac(%edx)
000008a8	movl	0x00000460(%ebx),%eax
000008ae	testb	$0x02,%al
000008b0	je	0x000008f4
000008b2	movl	(%ebx),%eax
000008b4	movl	%ebx,(%esp)
000008b7	call	*0x0000073c(%eax)
000008bd	testl	%eax,%eax
000008bf	jne	0x0000090f
000008c1	andl	$0xfd,0x00000460(%ebx)
000008c8	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
000008d0	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
000008d8	movl	$0x00000001,0x04(%esp)
000008e0	movl	0x00000474(%ebx),%eax
000008e6	movl	%eax,(%esp)
000008e9	calll	__ZN16IO80211Interface11postMessageEmPvm
000008ee	movl	0x00000460(%ebx),%eax
000008f4	andl	$0xfb,%eax
000008f7	movl	%eax,0x00000460(%ebx)
000008fd	movl	0x00000464(%ebx),%eax
00000903	movl	%eax,(%esp)
00000906	calll	_IOLockUnlock
0000090b	xorl	%eax,%eax
0000090d	jmp	0x0000092e
0000090f	movl	$0x00003954,(%esp)
00000916	calll	_IOLog
0000091b	movl	0x00000464(%ebx),%eax
00000921	movl	%eax,(%esp)
00000924	calll	_IOLockUnlock
00000929	movl	$0xe00002bc,%eax
0000092e	addl	$0x14,%esp
00000931	popl	%ebx
00000932	leave
00000933	ret
__ZN20VoodooWirelessDevice17createOutputQueueEv:
00000934	pushl	%ebp
00000935	movl	%esp,%ebp
00000937	subl	$0x18,%esp
0000093a	movl	%ebx,0xf8(%ebp)
0000093d	movl	0x08(%ebp),%ebx
00000940	movl	%esi,0xfc(%ebp)
00000943	movl	(%ebx),%eax
00000945	movl	0x0000045c(%ebx),%esi
0000094b	movl	%ebx,(%esp)
0000094e	call	*0x00000334(%eax)
00000954	movl	%esi,0x08(%esp)
00000958	movl	%ebx,(%esp)
0000095b	movl	%eax,0x04(%esp)
0000095f	calll	__ZN18IOGatedOutputQueue10withTargetEP19IONetworkControllerP10IOWorkLoopm
00000964	movl	%eax,0x00000478(%ebx)
0000096a	movl	0xf8(%ebp),%ebx
0000096d	movl	0xfc(%ebp),%esi
00000970	leave
00000971	ret
__ZN20VoodooWirelessDevice12outputPacketEP6__mbufPv:
00000972	pushl	%ebp
00000973	movl	%esp,%ebp
00000975	subl	$0x78,%esp
00000978	movl	0x08(%ebp),%eax
0000097b	movl	%ebx,0xf4(%ebp)
0000097e	movl	%esi,0xf8(%ebp)
00000981	movl	%edi,0xfc(%ebp)
00000984	cmpb	$0x02,0x00000468(%eax)
0000098b	movl	%eax,%edx
0000098d	jne	0x000009b5
0000098f	movl	0x0c(%ebp),%eax
00000992	movl	%eax,(%esp)
00000995	calll	_mbuf_type
0000099a	testl	%eax,%eax
0000099c	jel	0x00000c1c
000009a2	movl	0x0c(%ebp),%edx
000009a5	movl	%edx,(%esp)
000009a8	calll	_mbuf_len
000009ad	cmpl	$0x0e,%eax
000009b0	ja	0x000009d7
000009b2	movl	0x08(%ebp),%edx
000009b5	movl	(%edx),%eax
000009b7	movl	0x0c(%ebp),%edx
000009ba	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
000009c2	movl	%edx,0x04(%esp)
000009c6	movl	0x08(%ebp),%edx
000009c9	movl	%edx,(%esp)
000009cc	call	*0x00000520(%eax)
000009d2	jmpl	0x00000c1c
000009d7	movl	0x0c(%ebp),%eax
000009da	leal	0xdc(%ebp),%edi
000009dd	movl	%eax,(%esp)
000009e0	calll	_mbuf_data
000009e5	leal	0xe2(%ebp),%edx
000009e8	movl	%edx,0xac(%ebp)
000009eb	movl	%edx,0x04(%esp)
000009ef	movl	$0x00000006,0x08(%esp)
000009f7	movl	%eax,%ebx
000009f9	movl	0x08(%ebp),%eax
000009fc	addl	$0x0000054c,%eax
00000a01	movl	%eax,(%esp)
00000a04	calll	_bcopy
00000a09	movl	$0x00000006,0x08(%esp)
00000a11	movl	%edi,0x04(%esp)
00000a15	movl	%ebx,(%esp)
00000a18	calll	_bcopy
00000a1d	leal	0xd6(%ebp),%eax
00000a20	movl	%eax,0xa8(%ebp)
00000a23	movl	%eax,0x04(%esp)
00000a27	leal	0x06(%ebx),%eax
00000a2a	movl	$0x00000006,0x08(%esp)
00000a32	movl	%eax,(%esp)
00000a35	calll	_bcopy
00000a3a	cmpw	$0x0806,0x0c(%ebx)
00000a40	jne	0x00000a65
00000a42	movl	0x0c(%ebp),%edx
00000a45	movl	%edx,(%esp)
00000a48	calll	_mbuf_data
00000a4d	movl	$0x00000006,0x08(%esp)
00000a55	movl	$_llc_arp.22025,(%esp)
00000a5c	addl	$0x06,%eax
00000a5f	movl	%eax,0x04(%esp)
00000a63	jmp	0x00000a86
00000a65	movl	0x0c(%ebp),%eax
00000a68	movl	%eax,(%esp)
00000a6b	calll	_mbuf_data
00000a70	movl	$0x00000006,0x08(%esp)
00000a78	movl	$_llc_dat.22024,(%esp)
00000a7f	addl	$0x06,%eax
00000a82	movl	%eax,0x04(%esp)
00000a86	calll	_bcopy
00000a8b	movl	0x0c(%ebp),%edx
00000a8e	leal	0xbe(%ebp),%esi
00000a91	movl	$0x00000006,0x04(%esp)
00000a99	movl	%edx,(%esp)
00000a9c	calll	_mbuf_adj
00000aa1	movl	$0x00000018,0x04(%esp)
00000aa9	movl	%esi,(%esp)
00000aac	calll	_bzero
00000ab1	movzwl	0xbe(%ebp),%eax
00000ab5	movl	$0x00000006,0x08(%esp)
00000abd	andb	$0x03,%al
00000abf	orw	$0x0108,%ax
00000ac3	movw	%ax,0xbe(%ebp)
00000ac7	leal	0xc2(%ebp),%eax
00000aca	movl	%eax,0x04(%esp)
00000ace	movl	0xac(%ebp),%eax
00000ad1	movl	%eax,(%esp)
00000ad4	calll	_bcopy
00000ad9	leal	0xce(%ebp),%eax
00000adc	movl	%eax,0x04(%esp)
00000ae0	movl	$0x00000006,0x08(%esp)
00000ae8	movl	%edi,(%esp)
00000aeb	calll	_bcopy
00000af0	movl	0xa8(%ebp),%edx
00000af3	leal	0xc8(%ebp),%eax
00000af6	movl	%eax,0x04(%esp)
00000afa	movl	$0x00000006,0x08(%esp)
00000b02	movl	%edx,(%esp)
00000b05	calll	_bcopy
00000b0a	movl	0x08(%ebp),%edx
00000b0d	movl	(%edx),%eax
00000b0f	movl	0x00000510(%eax),%ebx
00000b15	movl	0x0c(%ebp),%eax
00000b18	movl	%eax,(%esp)
00000b1b	calll	_mbuf_pkthdr_len
00000b20	movl	0x08(%ebp),%edx
00000b23	movl	%edx,(%esp)
00000b26	addl	$0x18,%eax
00000b29	movl	%eax,0x04(%esp)
00000b2d	call	*%ebx
00000b2f	testl	%eax,%eax
00000b31	movl	%eax,0xb0(%ebp)
00000b34	jel	0x00000c1c
00000b3a	movl	%esi,0x0c(%esp)
00000b3e	movl	$0x00000001,0x10(%esp)
00000b46	movl	$0x00000018,0x08(%esp)
00000b4e	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x04(%esp)
00000b56	movl	%eax,(%esp)
00000b59	calll	_mbuf_copyback
00000b5e	movl	0x0c(%ebp),%eax
00000b61	movl	%eax,(%esp)
00000b64	calll	_mbuf_pkthdr_len
00000b69	movl	0x0c(%ebp),%esi
00000b6c	movl	%eax,%edi
00000b6e	movl	%eax,0xb4(%ebp)
00000b71	jmp	0x00000bc0
00000b73	movl	%esi,(%esp)
00000b76	calll	_mbuf_data
00000b7b	movl	%esi,(%esp)
00000b7e	movl	%eax,%ebx
00000b80	calll	_mbuf_len
00000b85	movl	0xb0(%ebp),%edx
00000b88	movl	$0x00000001,0x10(%esp)
00000b90	movl	%ebx,0x0c(%esp)
00000b94	movl	%edx,(%esp)
00000b97	movl	%eax,0x08(%esp)
00000b9b	movl	0xb4(%ebp),%eax
00000b9e	subl	%edi,%eax
00000ba0	addl	$0x18,%eax
00000ba3	movl	%eax,0x04(%esp)
00000ba7	calll	_mbuf_copyback
00000bac	movl	%esi,(%esp)
00000baf	calll	_mbuf_len
00000bb4	movl	%esi,(%esp)
00000bb7	subl	%eax,%edi
00000bb9	calll	_mbuf_next
00000bbe	movl	%eax,%esi
00000bc0	testl	%edi,%edi
00000bc2	setne	%dl
00000bc5	testl	%esi,%esi
00000bc7	setne	%al
00000bca	testb	%al,%dl
00000bcc	jne	0x00000b73
00000bce	movl	0x08(%ebp),%edx
00000bd1	xorl	%ebx,%ebx
00000bd3	movl	(%edx),%eax
00000bd5	movl	0x0c(%ebp),%edx
00000bd8	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00000be0	movl	%edx,0x04(%esp)
00000be4	movl	0x08(%ebp),%edx
00000be7	movl	%edx,(%esp)
00000bea	call	*0x00000520(%eax)
00000bf0	movl	%esi,%edx
00000bf2	andl	$0xffffff00,%edx
00000bf8	movl	%edx,%esi
00000bfa	movl	0x08(%ebp),%edx
00000bfd	movl	(%edx),%eax
00000bff	movl	0xb0(%ebp),%edx
00000c02	movl	%ebx,0x04(%esp)
00000c06	movl	%esi,0x08(%esp)
00000c0a	movl	%edx,0x0c(%esp)
00000c0e	movl	0x08(%ebp),%edx
00000c11	movl	%edx,(%esp)
00000c14	call	*0x0000075c(%eax)
00000c1a	jmp	0x00000c21
00000c1c	movl	$0x00000001,%eax
00000c21	movl	0xf4(%ebp),%ebx
00000c24	movl	0xf8(%ebp),%esi
00000c27	movl	0xfc(%ebp),%edi
00000c2a	leave
00000c2b	ret
__ZN20VoodooWirelessDevice21scanResultsAreSimilarEPK22apple80211_scan_resultS2_:
00000c2c	pushl	%ebp
00000c2d	movl	%esp,%ebp
00000c2f	subl	$0x28,%esp
00000c32	movl	%esi,0xf8(%ebp)
00000c35	movl	0x0c(%ebp),%esi
00000c38	movl	%edi,0xfc(%ebp)
00000c3b	movl	0x10(%ebp),%edi
00000c3e	movl	%ebx,0xf4(%ebp)
00000c41	movzbl	0x5c(%esi),%ebx
00000c45	movzbl	0x5c(%edi),%edx
00000c49	movzbl	%bl,%eax
00000c4c	cmpb	%dl,%bl
00000c4e	movzbl	%dl,%ecx
00000c51	cmovael	%ecx,%eax
00000c54	movl	%eax,0x08(%esp)
00000c58	leal	0x5d(%edi),%eax
00000c5b	movl	%eax,0x04(%esp)
00000c5f	leal	0x5d(%esi),%eax
00000c62	movl	%eax,(%esp)
00000c65	calll	_strncmp
00000c6a	testl	%eax,%eax
00000c6c	jne	0x00000cd6
00000c6e	leal	0x18(%edi),%eax
00000c71	movl	%eax,0x04(%esp)
00000c75	leal	0x18(%esi),%eax
00000c78	movl	$0x00000006,0x08(%esp)
00000c80	movl	%eax,(%esp)
00000c83	calll	_strncmp
00000c88	testl	%eax,%eax
00000c8a	jne	0x00000cd6
00000c8c	movl	0x08(%esi),%eax
00000c8f	cmpl	0x08(%edi),%eax
00000c92	jne	0x00000cd6
00000c94	movl	0x0c(%esi),%eax
00000c97	cmpl	0x0c(%edi),%eax
00000c9a	jne	0x00000cd6
00000c9c	movzwl	0x16(%esi),%eax
00000ca0	cmpw	0x16(%edi),%ax
00000ca4	jne	0x00000cd6
00000ca6	movzbl	0x1e(%esi),%eax
00000caa	cmpb	0x1e(%edi),%al
00000cad	jne	0x00000cd6
00000caf	movl	%esi,%ebx
00000cb1	movl	%edi,%ecx
00000cb3	xorl	%esi,%esi
00000cb5	movzbl	%al,%edi
00000cb8	jmp	0x00000ccb
00000cba	movl	0x20(%ebx),%edx
00000cbd	addl	$0x04,%ebx
00000cc0	movl	0x20(%ecx),%eax
00000cc3	addl	$0x04,%ecx
00000cc6	cmpl	%eax,%edx
00000cc8	jne	0x00000cd6
00000cca	incl	%esi
00000ccb	cmpl	%edi,%esi
00000ccd	jl	0x00000cba
00000ccf	movl	$0x00000001,%eax
00000cd4	jmp	0x00000cd8
00000cd6	xorl	%eax,%eax
00000cd8	movl	0xf4(%ebp),%ebx
00000cdb	movl	0xf8(%ebp),%esi
00000cde	movl	0xfc(%ebp),%edi
00000ce1	leave
00000ce2	ret
00000ce3	nop
__ZN20VoodooWirelessDevice14findScanResultEP21apple80211_assoc_data:
00000ce4	pushl	%ebp
00000ce5	movl	%esp,%ebp
00000ce7	subl	$0x48,%esp
00000cea	movl	%esi,0xf8(%ebp)
00000ced	movl	0x0c(%ebp),%esi
00000cf0	movl	%ebx,0xf4(%ebp)
00000cf3	movl	%edi,0xfc(%ebp)
00000cf6	testl	%esi,%esi
00000cf8	jel	0x00000e01
00000cfe	movl	0x08(%ebp),%edx
00000d01	movl	0x00000484(%edx),%eax
00000d07	movl	(%eax),%edx
00000d09	movl	%eax,(%esp)
00000d0c	call	*0x000000a0(%edx)
00000d12	testl	%eax,%eax
00000d14	jel	0x00000e01
00000d1a	leal	0x30(%esi),%eax
00000d1d	xorl	%edi,%edi
00000d1f	movl	%eax,0xd0(%ebp)
00000d22	movl	0xd0(%ebp),%edx
00000d25	leal	0xe2(%ebp),%eax
00000d28	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0xe2(%ebp)
00000d2c	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0xe3(%ebp)
00000d30	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0xe4(%ebp)
00000d34	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0xe5(%ebp)
00000d38	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0xe6(%ebp)
00000d3c	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0xe7(%ebp)
00000d40	movl	$0x00000006,0x08(%esp)
00000d48	movl	%eax,0x04(%esp)
00000d4c	movl	%edx,(%esp)
00000d4f	calll	_strncmp
00000d54	movl	%eax,0xd4(%ebp)
00000d57	jmpl	0x00000de5
00000d5c	movl	0x08(%ebp),%edx
00000d5f	movl	0x00000484(%edx),%eax
00000d65	movl	(%eax),%edx
00000d67	movl	%edi,0x04(%esp)
00000d6b	movl	%eax,(%esp)
00000d6e	call	*0x000000fc(%edx)
00000d74	movl	__ZN6OSData9metaClassE,%edx
00000d7a	movl	%edx,0x04(%esp)
00000d7e	movl	%eax,(%esp)
00000d81	calll	__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass
00000d86	testl	%eax,%eax
00000d88	movl	%eax,%edx
00000d8a	je	0x00000de4
00000d8c	movl	(%eax),%eax
00000d8e	movl	%edx,(%esp)
00000d91	call	*0x000000c4(%eax)
00000d97	movl	%eax,%ebx
00000d99	movl	0xd4(%ebp),%eax
00000d9c	testl	%eax,%eax
00000d9e	jne	0x00000dbe
00000da0	leal	0x18(%ebx),%eax
00000da3	movl	%eax,0x04(%esp)
00000da7	movl	0xd0(%ebp),%eax
00000daa	movl	$0x00000006,0x08(%esp)
00000db2	movl	%eax,(%esp)
00000db5	calll	_strncmp
00000dba	testl	%eax,%eax
00000dbc	je	0x00000e03
00000dbe	movzbl	0x5c(%ebx),%eax
00000dc2	movl	0x0c(%esi),%edx
00000dc5	cmpl	%edx,%eax
00000dc7	cmoval	%edx,%eax
00000dca	movl	%eax,0x08(%esp)
00000dce	leal	0x10(%esi),%eax
00000dd1	movl	%eax,0x04(%esp)
00000dd5	leal	0x5d(%ebx),%eax
00000dd8	movl	%eax,(%esp)
00000ddb	calll	_strncmp
00000de0	testl	%eax,%eax
00000de2	je	0x00000e03
00000de4	incl	%edi
00000de5	movl	0x08(%ebp),%edx
00000de8	movl	0x00000484(%edx),%eax
00000dee	movl	(%eax),%edx
00000df0	movl	%eax,(%esp)
00000df3	call	*0x000000a0(%edx)
00000df9	cmpl	%edi,%eax
00000dfb	jal	0x00000d5c
00000e01	xorl	%ebx,%ebx
00000e03	movl	%ebx,%eax
00000e05	movl	0xf8(%ebp),%esi
00000e08	movl	0xf4(%ebp),%ebx
00000e0b	movl	0xfc(%ebp),%edi
00000e0e	leave
00000e0f	ret
__ZNK20VoodooWirelessDevice15newVendorStringEv:
00000e10	pushl	%ebp
00000e11	movl	%esp,%ebp
00000e13	movl	0x08(%ebp),%eax
00000e16	movl	0x000002a0(%eax),%eax
00000e1c	leave
00000e1d	ret
__ZNK20VoodooWirelessDevice14newModelStringEv:
00000e1e	pushl	%ebp
00000e1f	movl	%esp,%ebp
00000e21	movl	0x08(%ebp),%eax
00000e24	movl	0x000002a4(%eax),%eax
00000e2a	leave
00000e2b	ret
__ZNK20VoodooWirelessDevice17newRevisionStringEv:
00000e2c	pushl	%ebp
00000e2d	movl	%esp,%ebp
00000e2f	movl	0x08(%ebp),%eax
00000e32	movl	0x000002a8(%eax),%eax
00000e38	leave
00000e39	ret
__ZN20VoodooWirelessDevice18getHardwareAddressEP17IOEthernetAddress:
00000e3a	pushl	%ebp
00000e3b	movl	%esp,%ebp
00000e3d	subl	$0x18,%esp
00000e40	movl	0x0c(%ebp),%eax
00000e43	movl	$0x00000006,0x08(%esp)
00000e4b	movl	%eax,0x04(%esp)
00000e4f	movl	0x08(%ebp),%eax
00000e52	addl	$0x000002b4,%eax
00000e57	movl	%eax,(%esp)
00000e5a	calll	_bcopy
00000e5f	xorl	%eax,%eax
00000e61	leave
00000e62	ret
00000e63	nop
__ZNK20VoodooWirelessDevice16getMaxPacketSizeEPm:
00000e64	pushl	%ebp
00000e65	movl	%esp,%ebp
00000e67	movl	0x08(%ebp),%eax
00000e6a	movl	0x00000458(%eax),%edx
00000e70	movl	0x0c(%ebp),%eax
00000e73	movl	%edx,(%eax)
00000e75	xorl	%eax,%eax
00000e77	leave
00000e78	ret
00000e79	nop
__ZN20VoodooWirelessDevice18setPromiscuousModeEb:
00000e7a	pushl	%ebp
00000e7b	xorl	%eax,%eax
00000e7d	movl	%esp,%ebp
00000e7f	leave
00000e80	ret
00000e81	nop
__ZN20VoodooWirelessDevice16setMulticastModeEb:
00000e82	pushl	%ebp
00000e83	xorl	%eax,%eax
00000e85	movl	%esp,%ebp
00000e87	leave
00000e88	ret
00000e89	nop
__ZN20VoodooWirelessDevice16setMulticastListEP17IOEthernetAddressm:
00000e8a	pushl	%ebp
00000e8b	xorl	%eax,%eax
00000e8d	movl	%esp,%ebp
00000e8f	leave
00000e90	ret
00000e91	nop
__ZN20VoodooWirelessDevice21monitorModeSetEnabledEP16IO80211Interfacebm:
00000e92	pushl	%ebp
00000e93	xorl	%eax,%eax
00000e95	movl	%esp,%ebp
00000e97	leave
00000e98	ret
00000e99	nop
__ZN20VoodooWirelessDevice17allocateResourcesEP9IOService:
00000e9a	pushl	%ebp
00000e9b	movl	$0xe00002c7,%eax
00000ea0	movl	%esp,%ebp
00000ea2	leave
00000ea3	ret
__ZN20VoodooWirelessDevice13freeResourcesEP9IOService:
00000ea4	pushl	%ebp
00000ea5	movl	%esp,%ebp
00000ea7	leave
00000ea8	ret
00000ea9	nop
__ZN20VoodooWirelessDevice11turnPowerOnEv:
00000eaa	pushl	%ebp
00000eab	movl	$0xe00002c7,%eax
00000eb0	movl	%esp,%ebp
00000eb2	leave
00000eb3	ret
__ZN20VoodooWirelessDevice12turnPowerOffEv:
00000eb4	pushl	%ebp
00000eb5	movl	$0xe00002c7,%eax
00000eba	movl	%esp,%ebp
00000ebc	leave
00000ebd	ret
__ZN20VoodooWirelessDevice9startScanEPKN19org_voodoo_wireless14ScanParametersEPKNS0_4IEEE11ChannelListE:
00000ebe	pushl	%ebp
00000ebf	movl	$0xe00002c7,%eax
00000ec4	movl	%esp,%ebp
00000ec6	leave
00000ec7	ret
__ZN20VoodooWirelessDevice9abortScanEv:
00000ec8	pushl	%ebp
00000ec9	movl	%esp,%ebp
00000ecb	leave
00000ecc	ret
00000ecd	nop
__ZN20VoodooWirelessDevice9associateEPKN19org_voodoo_wireless21AssociationParametersE:
00000ece	pushl	%ebp
00000ecf	movl	$0xe00002c7,%eax
00000ed4	movl	%esp,%ebp
00000ed6	leave
00000ed7	ret
__ZN20VoodooWirelessDevice12disassociateEv:
00000ed8	pushl	%ebp
00000ed9	movl	$0xe00002c7,%eax
00000ede	movl	%esp,%ebp
00000ee0	leave
00000ee1	ret
__ZN20VoodooWirelessDevice15getHardwareInfoEPN19org_voodoo_wireless12HardwareInfoE:
00000ee2	pushl	%ebp
00000ee3	movl	%esp,%ebp
00000ee5	leave
00000ee6	ret
00000ee7	nop
__ZN20VoodooWirelessDevice16getConfigurationEN19org_voodoo_wireless18HardwareConfigTypeEPv:
00000ee8	pushl	%ebp
00000ee9	movl	$0xe00002c7,%eax
00000eee	movl	%esp,%ebp
00000ef0	leave
00000ef1	ret
__ZN20VoodooWirelessDevice16setConfigurationEN19org_voodoo_wireless18HardwareConfigTypeEPv:
00000ef2	pushl	%ebp
00000ef3	movl	$0xe00002c7,%eax
00000ef8	movl	%esp,%ebp
00000efa	leave
00000efb	ret
__ZN20VoodooWirelessDevice11outputFrameEN19org_voodoo_wireless13TxFrameHeaderEP6__mbuf:
00000efc	pushl	%ebp
00000efd	movl	$0xe00002c7,%eax
00000f02	movl	%esp,%ebp
00000f04	leave
00000f05	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice0Ev:
00000f06	pushl	%ebp
00000f07	movl	%esp,%ebp
00000f09	subl	$0x18,%esp
00000f0c	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x04(%esp)
00000f14	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000f1b	calll	__ZNK11OSMetaClass14reservedCalledEi
00000f20	leave
00000f21	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice1Ev:
00000f22	pushl	%ebp
00000f23	movl	%esp,%ebp
00000f25	subl	$0x18,%esp
00000f28	movl	$0x00000001,0x04(%esp)
00000f30	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000f37	calll	__ZNK11OSMetaClass14reservedCalledEi
00000f3c	leave
00000f3d	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice2Ev:
00000f3e	pushl	%ebp
00000f3f	movl	%esp,%ebp
00000f41	subl	$0x18,%esp
00000f44	movl	$0x00000002,0x04(%esp)
00000f4c	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000f53	calll	__ZNK11OSMetaClass14reservedCalledEi
00000f58	leave
00000f59	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice3Ev:
00000f5a	pushl	%ebp
00000f5b	movl	%esp,%ebp
00000f5d	subl	$0x18,%esp
00000f60	movl	$0x00000003,0x04(%esp)
00000f68	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000f6f	calll	__ZNK11OSMetaClass14reservedCalledEi
00000f74	leave
00000f75	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice4Ev:
00000f76	pushl	%ebp
00000f77	movl	%esp,%ebp
00000f79	subl	$0x18,%esp
00000f7c	movl	$0x00000004,0x04(%esp)
00000f84	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000f8b	calll	__ZNK11OSMetaClass14reservedCalledEi
00000f90	leave
00000f91	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice5Ev:
00000f92	pushl	%ebp
00000f93	movl	%esp,%ebp
00000f95	subl	$0x18,%esp
00000f98	movl	$0x00000005,0x04(%esp)
00000fa0	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000fa7	calll	__ZNK11OSMetaClass14reservedCalledEi
00000fac	leave
00000fad	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice6Ev:
00000fae	pushl	%ebp
00000faf	movl	%esp,%ebp
00000fb1	subl	$0x18,%esp
00000fb4	movl	$0x00000006,0x04(%esp)
00000fbc	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000fc3	calll	__ZNK11OSMetaClass14reservedCalledEi
00000fc8	leave
00000fc9	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice7Ev:
00000fca	pushl	%ebp
00000fcb	movl	%esp,%ebp
00000fcd	subl	$0x18,%esp
00000fd0	movl	$0x00000007,0x04(%esp)
00000fd8	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000fdf	calll	__ZNK11OSMetaClass14reservedCalledEi
00000fe4	leave
00000fe5	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice8Ev:
00000fe6	pushl	%ebp
00000fe7	movl	%esp,%ebp
00000fe9	subl	$0x18,%esp
00000fec	movl	$0x00000008,0x04(%esp)
00000ff4	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00000ffb	calll	__ZNK11OSMetaClass14reservedCalledEi
00001000	leave
00001001	ret
__ZN20VoodooWirelessDevice30_RESERVEDVoodooWirelessDevice9Ev:
00001002	pushl	%ebp
00001003	movl	%esp,%ebp
00001005	subl	$0x18,%esp
00001008	movl	$0x00000009,0x04(%esp)
00001010	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00001017	calll	__ZNK11OSMetaClass14reservedCalledEi
0000101c	leave
0000101d	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice10Ev:
0000101e	pushl	%ebp
0000101f	movl	%esp,%ebp
00001021	subl	$0x18,%esp
00001024	movl	$__ZN17IO80211Controller25monitorPacketHeaderLengthEP16IO80211Interface,0x04(%esp)
0000102c	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00001033	calll	__ZNK11OSMetaClass14reservedCalledEi
00001038	leave
00001039	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice11Ev:
0000103a	pushl	%ebp
0000103b	movl	%esp,%ebp
0000103d	subl	$0x18,%esp
00001040	movl	$0x0000000b,0x04(%esp)
00001048	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
0000104f	calll	__ZNK11OSMetaClass14reservedCalledEi
00001054	leave
00001055	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice12Ev:
00001056	pushl	%ebp
00001057	movl	%esp,%ebp
00001059	subl	$0x18,%esp
0000105c	movl	$0x0000000c,0x04(%esp)
00001064	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
0000106b	calll	__ZNK11OSMetaClass14reservedCalledEi
00001070	leave
00001071	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice13Ev:
00001072	pushl	%ebp
00001073	movl	%esp,%ebp
00001075	subl	$0x18,%esp
00001078	movl	$0x0000000d,0x04(%esp)
00001080	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00001087	calll	__ZNK11OSMetaClass14reservedCalledEi
0000108c	leave
0000108d	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice14Ev:
0000108e	pushl	%ebp
0000108f	movl	%esp,%ebp
00001091	subl	$0x18,%esp
00001094	movl	$0x0000000e,0x04(%esp)
0000109c	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
000010a3	calll	__ZNK11OSMetaClass14reservedCalledEi
000010a8	leave
000010a9	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice15Ev:
000010aa	pushl	%ebp
000010ab	movl	%esp,%ebp
000010ad	subl	$0x18,%esp
000010b0	movl	$0x0000000f,0x04(%esp)
000010b8	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
000010bf	calll	__ZNK11OSMetaClass14reservedCalledEi
000010c4	leave
000010c5	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice16Ev:
000010c6	pushl	%ebp
000010c7	movl	%esp,%ebp
000010c9	subl	$0x18,%esp
000010cc	movl	$0x00000010,0x04(%esp)
000010d4	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
000010db	calll	__ZNK11OSMetaClass14reservedCalledEi
000010e0	leave
000010e1	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice17Ev:
000010e2	pushl	%ebp
000010e3	movl	%esp,%ebp
000010e5	subl	$0x18,%esp
000010e8	movl	$0x00000011,0x04(%esp)
000010f0	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
000010f7	calll	__ZNK11OSMetaClass14reservedCalledEi
000010fc	leave
000010fd	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice18Ev:
000010fe	pushl	%ebp
000010ff	movl	%esp,%ebp
00001101	subl	$0x18,%esp
00001104	movl	$__ZN17IO80211Controller10monitorDLTEP16IO80211Interface,0x04(%esp)
0000110c	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00001113	calll	__ZNK11OSMetaClass14reservedCalledEi
00001118	leave
00001119	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice19Ev:
0000111a	pushl	%ebp
0000111b	movl	%esp,%ebp
0000111d	subl	$0x18,%esp
00001120	movl	$0x00000013,0x04(%esp)
00001128	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
0000112f	calll	__ZNK11OSMetaClass14reservedCalledEi
00001134	leave
00001135	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice20Ev:
00001136	pushl	%ebp
00001137	movl	%esp,%ebp
00001139	subl	$0x18,%esp
0000113c	movl	$0x00000014,0x04(%esp)
00001144	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
0000114b	calll	__ZNK11OSMetaClass14reservedCalledEi
00001150	leave
00001151	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice21Ev:
00001152	pushl	%ebp
00001153	movl	%esp,%ebp
00001155	subl	$0x18,%esp
00001158	movl	$0x00000015,0x04(%esp)
00001160	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00001167	calll	__ZNK11OSMetaClass14reservedCalledEi
0000116c	leave
0000116d	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice22Ev:
0000116e	pushl	%ebp
0000116f	movl	%esp,%ebp
00001171	subl	$0x18,%esp
00001174	movl	$0x00000016,0x04(%esp)
0000117c	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
00001183	calll	__ZNK11OSMetaClass14reservedCalledEi
00001188	leave
00001189	ret
__ZN20VoodooWirelessDevice31_RESERVEDVoodooWirelessDevice23Ev:
0000118a	pushl	%ebp
0000118b	movl	%esp,%ebp
0000118d	subl	$0x18,%esp
00001190	movl	$0x00000017,0x04(%esp)
00001198	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
0000119f	calll	__ZNK11OSMetaClass14reservedCalledEi
000011a4	leave
000011a5	ret
__Z41__static_initialization_and_destruction_0ii:
000011a6	pushl	%ebp
000011a7	movl	%esp,%ebp
000011a9	subl	$0x18,%esp
000011ac	cmpl	$0x0000ffff,%edx
000011b2	movl	%ebx,0xf8(%ebp)
000011b5	sete	%bl
000011b8	cmpl	$0x01,%eax
000011bb	movl	%esi,0xfc(%ebp)
000011be	movl	%eax,%esi
000011c0	sete	%al
000011c3	testb	%al,%bl
000011c5	je	0x000011d3
000011c7	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
000011ce	calll	__ZN20VoodooWirelessDevice9MetaClassC1Ev
000011d3	testl	%esi,%esi
000011d5	sete	%al
000011d8	testb	%al,%bl
000011da	je	0x000011e9
000011dc	movl	$__ZN20VoodooWirelessDevice10gMetaClassE,(%esp)
000011e3	call	*__ZTVN20VoodooWirelessDevice9MetaClassE+0x00000008
000011e9	movl	0xf8(%ebp),%ebx
000011ec	movl	0xfc(%ebp),%esi
000011ef	leave
000011f0	ret
000011f1	nop
__ZN20VoodooWirelessDevice9MetaClassD0Ev:
000011f2	pushl	%ebp
000011f3	movl	%esp,%ebp
000011f5	pushl	%ebx
000011f6	subl	$0x14,%esp
000011f9	movl	0x08(%ebp),%ebx
000011fc	movl	$__ZTVN20VoodooWirelessDevice9MetaClassE,(%ebx)
00001202	movl	%ebx,(%esp)
00001205	calll	__ZN11OSMetaClassD2Ev
0000120a	movl	%ebx,%eax
0000120c	addl	$0x14,%esp
0000120f	popl	%ebx
00001210	leave
00001211	ret
__GLOBAL__I__ZN20VoodooWirelessDevice10gMetaClassE:
00001212	pushl	%ebp
00001213	movl	$0x0000ffff,%edx
00001218	movl	%esp,%ebp
0000121a	movl	$0x00000001,%eax
0000121f	leave
00001220	jmpl	__Z41__static_initialization_and_destruction_0ii
00001225	nop
__GLOBAL__D__ZN20VoodooWirelessDevice10gMetaClassE:
00001226	pushl	%ebp
00001227	movl	$0x0000ffff,%edx
0000122c	movl	%esp,%ebp
0000122e	xorl	%eax,%eax
00001230	leave
00001231	jmpl	__Z41__static_initialization_and_destruction_0ii
__ZN20VoodooWirelessDevice21apple80211Request_GETEiPv:
00001236	pushl	%ebp
00001237	movl	%esp,%ebp
00001239	subl	$0x48,%esp
0000123c	movl	0x0c(%ebp),%eax
0000123f	movl	%edi,0xfc(%ebp)
00001242	movl	0x10(%ebp),%edi
00001245	movl	%ebx,0xf4(%ebp)
00001248	movl	%esi,0xf8(%ebp)
0000124b	cmpl	$0x39,%eax
0000124e	ja	0x00001257
00001250	jmp	*0x00003524(,%eax,4)
00001257	movl	$0xe00002c7,%eax
0000125c	jmpl	0x00001a22
00001261	movl	$0x00000001,(%edi)
00001267	movl	0x08(%ebp),%eax
0000126a	movl	0x00000454(%eax),%esi
00001270	movl	%ebx,%eax
00001272	orl	$0x01,%eax
00001275	testl	$0x00000002,%esi
0000127b	movl	%esi,%edx
0000127d	cmovnel	%eax,%ebx
00001280	movl	%ebx,%eax
00001282	orl	$0x03,%eax
00001285	testl	$0x00000004,%esi
0000128b	cmovnel	%eax,%ebx
0000128e	shrl	$0x03,%edx
00001291	movl	%ebx,%eax
00001293	movl	%edx,%ecx
00001295	orl	$0x0d,%eax
00001298	andl	$0x01,%ecx
0000129b	cmovnel	%eax,%ebx
0000129e	movl	%esi,%eax
000012a0	shrl	$0x04,%eax
000012a3	movb	%cl,0xd7(%ebp)
000012a6	movl	%eax,%edx
000012a8	movl	%ebx,%ecx
000012aa	orl	$0x0e,%ecx
000012ad	andl	$0x01,%edx
000012b0	cmovnel	%ecx,%ebx
000012b3	cmpb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0xd7(%ebp)
000012b7	movb	%dl,0xe7(%ebp)
000012ba	je	0x000012c6
000012bc	movl	%ebx,%eax
000012be	orl	$0x0f,%eax
000012c1	testb	%dl,%dl
000012c3	cmovnel	%eax,%ebx
000012c6	movl	%ebx,%eax
000012c8	orl	$0x05,%eax
000012cb	testl	$0x00000020,%esi
000012d1	cmovnel	%eax,%ebx
000012d4	movl	%ebx,%eax
000012d6	orl	$0x07,%eax
000012d9	testl	$__ZN17IO80211Controller13enableFeatureE18IO80211FeatureCodePv,%esi
000012df	cmovnel	%eax,%ebx
000012e2	movl	%ebx,%eax
000012e4	orl	$0x0b,%eax
000012e7	testl	$0x00000080,%esi
000012ed	cmovnel	%eax,%ebx
000012f0	movl	%ebx,%eax
000012f2	orl	$0x06,%eax
000012f5	testl	$0x00000100,%esi
000012fb	cmovnel	%eax,%ebx
000012fe	movl	%ebx,%eax
00001300	orl	$0x08,%eax
00001303	testl	$0x00000200,%esi
00001309	cmovnel	%eax,%ebx
0000130c	movl	%ebx,%eax
0000130e	orl	$0x14,%eax
00001311	testl	$0x00000400,%esi
00001317	cmovnel	%eax,%ebx
0000131a	movl	%ebx,%eax
0000131c	orl	$0x09,%eax
0000131f	testl	$0x00000800,%esi
00001325	cmovnel	%eax,%ebx
00001328	movl	%ebx,%eax
0000132a	orl	$__ZN17IO80211Controller25monitorPacketHeaderLengthEP16IO80211Interface,%eax
0000132d	testl	$0x00001000,%esi
00001333	cmovnel	%eax,%ebx
00001336	movl	%ebx,%eax
00001338	orl	$0x10,%eax
0000133b	testl	$0x00002000,%esi
00001341	cmovnel	%eax,%ebx
00001344	movl	%ebx,%eax
00001346	orl	$0x11,%eax
00001349	testl	$0x00004000,%esi
0000134f	cmovnel	%eax,%ebx
00001352	movl	%ebx,%eax
00001354	orl	$0x13,%eax
00001357	testl	$0x00008000,%esi
0000135d	cmovnel	%eax,%ebx
00001360	movl	%ebx,%eax
00001362	orl	$__ZN17IO80211Controller10monitorDLTEP16IO80211Interface,%eax
00001365	andl	$0x00010000,%esi
0000136b	cmovnel	%eax,%ebx
0000136e	movzbl	%bh,%eax
00001371	movb	%bl,0x04(%edi)
00001374	shrl	$0x10,%ebx
00001377	movb	%al,0x05(%edi)
0000137a	movb	%bl,0x06(%edi)
0000137d	jmp	0x000013a0
0000137f	movl	$0x00000001,(%edi)
00001385	movl	$0x0000000f,0x08(%esp)
0000138d	movl	$0x00003988,0x04(%esp)
00001395	leal	0x04(%edi),%eax
00001398	movl	%eax,(%esp)
0000139b	calll	_strncpy
000013a0	xorl	%eax,%eax
000013a2	jmpl	0x00001a22
000013a7	movl	$0x00000001,(%edi)
000013ad	movl	0x08(%ebp),%ecx
000013b0	movl	0x000002ac(%ecx),%eax
000013b6	movl	(%eax),%edx
000013b8	movl	%eax,(%esp)
000013bb	call	*0x000000a0(%edx)
000013c1	movw	%ax,0x04(%edi)
000013c5	movl	0x08(%ebp),%esi
000013c8	movl	%eax,%ebx
000013ca	movl	0x000002ac(%esi),%eax
000013d0	jmp	0x000013fb
000013d2	movl	$0x00000001,(%edi)
000013d8	movl	0x08(%ebp),%edx
000013db	movl	0x000002a8(%edx),%eax
000013e1	movl	(%eax),%edx
000013e3	movl	%eax,(%esp)
000013e6	call	*0x000000a0(%edx)
000013ec	movw	%ax,0x04(%edi)
000013f0	movl	0x08(%ebp),%ecx
000013f3	movl	%eax,%ebx
000013f5	movl	0x000002a8(%ecx),%eax
000013fb	movl	(%eax),%edx
000013fd	movzwl	%bx,%ebx
00001400	movl	%eax,(%esp)
00001403	call	*0x000000ac(%edx)
00001409	movl	%ebx,0x08(%esp)
0000140d	movl	%eax,0x04(%esp)
00001411	leal	0x06(%edi),%eax
00001414	jmp	0x00001398
00001416	movl	$0x00000001,(%edi)
0000141c	movl	$0x00000004,0x08(%esp)
00001424	movl	$0x00003998,0x04(%esp)
0000142c	jmpl	0x00001395
00001431	movl	$0x00000001,(%edi)
00001437	movl	$0x00000005,0x04(%edi)
0000143e	jmpl	0x000013a0
00001443	movl	$0x00000001,(%edi)
00001449	jmpl	0x00001933
0000144e	movl	$0x00000001,(%edi)
00001454	leal	0x08(%edi),%edx
00001457	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x04(%edi)
0000145e	movl	0x08(%ebp),%ebx
00001461	movl	(%ebx),%eax
00001463	movl	%edx,0x08(%esp)
00001467	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x04(%esp)
0000146f	movl	%ebx,(%esp)
00001472	call	*0x00000754(%eax)
00001478	testl	%eax,%eax
0000147a	jnel	0x00001a16
00001480	movl	0x0000044c(%ebx),%eax
00001486	movl	0x08(%edi),%edx
00001489	cmpl	$0x01,%eax
0000148c	je	0x00001495
0000148e	cmpl	$0x02,%eax
00001491	jne	0x000014d1
00001493	jmp	0x000014b0
00001495	leal	0x88(%edx),%eax
00001498	movl	$0xffffff88,%edx
0000149d	cmpl	$0x87,%eax
000014a0	jle	0x000014d1
000014a2	cmpl	$0xec,%eax
000014a5	movl	%eax,%edx
000014a7	jle	0x000014d1
000014a9	movl	$0xffffffec,%edx
000014ae	jmp	0x000014d1
000014b0	leal	(%edx,%edx,4),%eax
000014b3	movl	$0xffffff88,%edx
000014b8	leal	0xffffff88(,%eax,4),%eax
000014bf	cmpl	$0x87,%eax
000014c2	jle	0x000014d1
000014c4	movl	%eax,%edx
000014c6	cmpl	$0xed,%eax
000014c9	movl	$0xffffffec,%eax
000014ce	cmovgel	%eax,%edx
000014d1	movl	%edx,0x08(%edi)
000014d4	jmpl	0x000013a0
000014d9	movl	$0x00000001,(%edi)
000014df	movl	$0x00000001,0x04(%edi)
000014e6	movl	0x08(%ebp),%esi
000014e9	movl	0x00000460(%esi),%eax
000014ef	shrl	%eax
000014f1	andl	$0x01,%eax
000014f4	jmpl	0x00001812
000014f9	movl	0x08(%ebp),%eax
000014fc	cmpb	$0x02,0x00000468(%eax)
00001503	jnel	0x00001a16
00001509	movl	$0x00000001,(%edi)
0000150f	movl	0x08(%ebp),%edx
00001512	movl	0x00000528(%edx),%eax
00001518	movl	%eax,0x04(%edi)
0000151b	movl	%eax,0x08(%esp)
0000151f	leal	0x08(%edi),%eax
00001522	movl	%eax,0x04(%esp)
00001526	movl	%edx,%eax
00001528	addl	$0x0000052c,%eax
0000152d	jmpl	0x00001897
00001532	movl	0x08(%ebp),%ecx
00001535	cmpb	$0x02,0x00000468(%ecx)
0000153c	jnel	0x00001a16
00001542	leal	0x04(%edi),%eax
00001545	movl	$0x00000001,(%edi)
0000154b	movl	%eax,0x04(%esp)
0000154f	movl	%ecx,%eax
00001551	addl	$0x000004a8,%eax
00001556	movl	$0x00000006,0x08(%esp)
0000155e	jmpl	0x00001897
00001563	movl	0x08(%ebp),%ebx
00001566	cmpb	$0x02,0x00000468(%ebx)
0000156d	jnel	0x00001a16
00001573	movl	$0x00000001,(%edi)
00001579	movl	0x00000498(%ebx),%eax
0000157f	movl	$0x00000089,0x0c(%edi)
00001586	movl	%eax,0x08(%edi)
00001589	jmpl	0x000013a0
0000158e	movl	$0x00000001,(%edi)
00001594	movl	0x08(%ebp),%esi
00001597	movl	%edi,%edx
00001599	xorl	%ebx,%ebx
0000159b	movl	0x000002c0(%esi),%eax
000015a1	movl	%esi,%ecx
000015a3	movl	%eax,0x04(%edi)
000015a6	jmp	0x000015c0
000015a8	movzbl	0x000002c0(%ecx),%eax
000015af	incl	%ebx
000015b0	movl	%eax,0x0c(%edx)
000015b3	movzwl	0x000002c2(%ecx),%eax
000015ba	movl	%eax,0x10(%edx)
000015bd	addl	$0x0c,%edx
000015c0	addl	$0x04,%ecx
000015c3	cmpl	0x04(%edi),%ebx
000015c6	jb	0x000015a8
000015c8	jmpl	0x000013a0
000015cd	movl	$0x00000001,(%edi)
000015d3	movl	0x08(%ebp),%eax
000015d6	movzbl	0x00000468(%eax),%edx
000015dd	cmpb	$0x02,%dl
000015e0	jne	0x000015ee
000015e2	movl	$0x00000004,0x04(%edi)
000015e9	jmpl	0x000013a0
000015ee	movl	0x08(%ebp),%ecx
000015f1	movl	0x00000460(%ecx),%eax
000015f7	testb	$0x08,%al
000015f9	jnel	0x00001a0a
000015ff	testb	$0x10,%al
00001601	jel	0x00001933
00001607	testb	%dl,%dl
00001609	je	0x00001615
0000160b	decb	%dl
0000160d	jnel	0x000013a0
00001613	jmp	0x00001621
00001615	movl	$0x00000002,0x04(%edi)
0000161c	jmpl	0x000013a0
00001621	movl	$0x00000003,0x04(%edi)
00001628	jmpl	0x000013a0
0000162d	movl	$0x00000001,(%edi)
00001633	movl	0x08(%ebp),%ebx
00001636	movl	0x000002bc(%ebx),%eax
0000163c	testb	$0x02,%al
0000163e	je	0x0000164a
00001640	orl	$0x02,0x04(%edi)
00001644	movl	0x000002bc(%ebx),%eax
0000164a	testb	$0x04,%al
0000164c	je	0x0000165b
0000164e	orl	$0x04,0x04(%edi)
00001652	movl	0x08(%ebp),%esi
00001655	movl	0x000002bc(%esi),%eax
0000165b	testb	$0x08,%al
0000165d	je	0x0000166c
0000165f	orl	$0x08,0x04(%edi)
00001663	movl	0x08(%ebp),%edx
00001666	movl	0x000002bc(%edx),%eax
0000166c	testb	$0x10,%al
0000166e	je	0x00001674
00001670	orl	$0x10,0x04(%edi)
00001674	movl	0x08(%ebp),%ecx
00001677	movl	$0x00000001,%eax
0000167c	cmpb	$0x02,0x00000468(%ecx)
00001683	jnel	0x00001812
00001689	movzwl	0x00000520(%ecx),%eax
00001690	jmpl	0x00001812
00001695	movl	$0x00000001,(%edi)
0000169b	movl	$0x00000001,0x04(%edi)
000016a2	movl	0x08(%ebp),%ebx
000016a5	movl	0x00000454(%ebx),%esi
000016ab	testl	$0x00000020,%esi
000016b1	je	0x000016c0
000016b3	movl	$0x00000003,0x04(%edi)
000016ba	movl	0x00000454(%ebx),%esi
000016c0	testl	$__ZN17IO80211Controller13enableFeatureE18IO80211FeatureCodePv,%esi
000016c6	je	0x000016d5
000016c8	orl	$0x08,0x04(%edi)
000016cc	movl	0x08(%ebp),%eax
000016cf	movl	0x00000454(%eax),%esi
000016d5	andl	$0x00000080,%esi
000016db	jel	0x000013a0
000016e1	orl	$0x10,0x04(%edi)
000016e5	jmpl	0x000013a0
000016ea	movl	$0x00000001,(%edi)
000016f0	movl	$0x00000001,0x04(%edi)
000016f7	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%edi)
000016fe	movl	0x08(%ebp),%edx
00001701	movl	0x000006a4(%edx),%eax
00001707	jmp	0x00001733
00001709	movl	0x08(%ebp),%ecx
0000170c	cmpb	$0x02,0x00000468(%ecx)
00001713	jnel	0x00001a16
00001719	movl	$0x00000001,(%edi)
0000171f	movl	$0x00000001,0x04(%edi)
00001726	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%edi)
0000172d	movl	0x000006a8(%ecx),%eax
00001733	movl	%eax,0x30(%edi)
00001736	movl	%eax,0x20(%edi)
00001739	movl	%eax,0x1c(%edi)
0000173c	movl	%eax,0x0c(%edi)
0000173f	jmpl	0x000013a0
00001744	movl	0x08(%ebp),%ebx
00001747	cmpb	$0x02,0x00000468(%ebx)
0000174e	jnel	0x00001a16
00001754	movl	$0x00000001,(%edi)
0000175a	movl	0x000006b0(%ebx),%eax
00001760	andl	$0x7f,%eax
00001763	sarl	%eax
00001765	movl	%eax,0x04(%edi)
00001768	movl	0x0000044c(%ebx),%eax
0000176e	movl	0x000006b4(%ebx),%edx
00001774	cmpl	$0x01,%eax
00001777	je	0x00001780
00001779	cmpl	$0x02,%eax
0000177c	jne	0x000017bc
0000177e	jmp	0x0000179b
00001780	leal	0x88(%edx),%eax
00001783	movl	$0xffffff88,%edx
00001788	cmpl	$0x87,%eax
0000178b	jle	0x000017bc
0000178d	cmpl	$0xec,%eax
00001790	movl	%eax,%edx
00001792	jle	0x000017bc
00001794	movl	$0xffffffec,%edx
00001799	jmp	0x000017bc
0000179b	leal	(%edx,%edx,4),%eax
0000179e	movl	$0xffffff88,%edx
000017a3	leal	0xffffff88(,%eax,4),%eax
000017aa	cmpl	$0x87,%eax
000017ad	jle	0x000017bc
000017af	movl	%eax,%edx
000017b1	cmpl	$0xed,%eax
000017b4	movl	$0xffffffec,%eax
000017b9	cmovgel	%eax,%edx
000017bc	movl	%edx,0x08(%edi)
000017bf	movl	$0x00000001,0x0c(%edi)
000017c6	jmpl	0x000013a0
000017cb	movl	0x08(%ebp),%esi
000017ce	cmpb	$0x02,0x00000468(%esi)
000017d5	jnel	0x00001a16
000017db	movl	$0x00000001,(%edi)
000017e1	leal	0x08(%edi),%edx
000017e4	movl	$0x00000001,0x04(%edi)
000017eb	movl	(%esi),%eax
000017ed	movl	%edx,0x08(%esp)
000017f1	movl	$0x00000005,0x04(%esp)
000017f9	movl	%esi,(%esp)
000017fc	call	*0x00000754(%eax)
00001802	testl	%eax,%eax
00001804	jnel	0x00001a16
0000180a	movl	0x08(%edi),%eax
0000180d	andl	$0x7f,%eax
00001810	shrl	%eax
00001812	movl	%eax,0x08(%edi)
00001815	jmpl	0x000013a0
0000181a	movl	0x08(%ebp),%eax
0000181d	cmpb	$0x02,0x00000468(%eax)
00001824	jnel	0x00001a16
0000182a	movl	%eax,%ecx
0000182c	movl	%edi,%edx
0000182e	xorl	%ebx,%ebx
00001830	movl	$0x00000001,(%edi)
00001836	jmp	0x0000184a
00001838	movl	0x000004ac(%ecx),%eax
0000183e	incl	%ebx
0000183f	andl	$0x7f,%eax
00001842	shrl	%eax
00001844	movl	%eax,0x0c(%edx)
00001847	addl	$0x0c,%edx
0000184a	movl	0x08(%ebp),%esi
0000184d	addl	$0x04,%ecx
00001850	movzbl	0x000004ae(%esi),%eax
00001857	cmpl	%eax,%ebx
00001859	jl	0x00001838
0000185b	jmpl	0x000013a0
00001860	movl	0x08(%ebp),%eax
00001863	cmpw	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000598(%eax)
0000186b	jel	0x00001a16
00001871	movl	$0x00000001,(%edi)
00001877	movl	0x08(%ebp),%edx
0000187a	movzwl	0x00000598(%edx),%eax
00001881	movw	%ax,0x04(%edi)
00001885	movl	%eax,0x08(%esp)
00001889	leal	0x06(%edi),%eax
0000188c	movl	%eax,0x04(%esp)
00001890	movl	%edx,%eax
00001892	addl	$0x0000059a,%eax
00001897	movl	%eax,(%esp)
0000189a	calll	_bcopy
0000189f	jmpl	0x000013a0
000018a4	movl	$0x00000001,(%edi)
000018aa	movl	0x08(%ebp),%ecx
000018ad	leal	0x04(%edi),%edx
000018b0	movl	(%ecx),%eax
000018b2	movl	%edx,0x08(%esp)
000018b6	movl	$0x00000002,0x04(%esp)
000018be	movl	%ecx,(%esp)
000018c1	call	*0x00000754(%eax)
000018c7	testl	%eax,%eax
000018c9	jel	0x000013a0
000018cf	jmpl	0x00001a16
000018d4	movl	0x08(%ebp),%ebx
000018d7	cmpb	$0x02,0x00000468(%ebx)
000018de	jel	0x00001a16
000018e4	movl	$0x00000001,(%edi)
000018ea	movl	0x0000046c(%ebx),%eax
000018f0	jmp	0x00001919
000018f2	movl	0x08(%ebp),%esi
000018f5	cmpb	$0x02,0x00000468(%esi)
000018fc	jnel	0x00001a16
00001902	movl	$0x00000001,(%edi)
00001908	movzwl	0x00000524(%esi),%eax
0000190f	movl	%eax,0x08(%edi)
00001912	movzwl	0x00000522(%esi),%eax
00001919	movl	%eax,0x04(%edi)
0000191c	jmpl	0x000013a0
00001921	movl	$0x00000001,(%edi)
00001927	movl	0x08(%ebp),%eax
0000192a	cmpb	$0x02,0x00000468(%eax)
00001931	jne	0x0000193f
00001933	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x04(%edi)
0000193a	jmpl	0x000013a0
0000193f	movl	0x08(%ebp),%edx
00001942	testb	$0x10,0x00000460(%edx)
00001949	jel	0x00001a0a
0000194f	jmpl	0x00001a1d
00001954	movl	0x08(%ebp),%ecx
00001957	testb	$0x08,0x00000460(%ecx)
0000195e	jnel	0x00001a1d
00001964	movl	0x0000048c(%ecx),%ebx
0000196a	testl	%ebx,%ebx
0000196c	jne	0x00001992
0000196e	movl	0x00000484(%ecx),%eax
00001974	movl	(%eax),%edx
00001976	movl	%eax,(%esp)
00001979	call	*0x000000a0(%edx)
0000197f	movl	0x08(%ebp),%ebx
00001982	movl	%eax,0x0000048c(%ebx)
00001988	movl	$0xffffffff,%eax
0000198d	jmpl	0x00001a22
00001992	movl	0x08(%ebp),%esi
00001995	movl	0x00000484(%esi),%edx
0000199b	movl	(%edx),%eax
0000199d	movl	0x000000fc(%eax),%ecx
000019a3	leal	0xff(%ebx),%eax
000019a6	movl	%eax,0x0000048c(%esi)
000019ac	movl	%edx,(%esp)
000019af	movl	%eax,0x04(%esp)
000019b3	call	*%ecx
000019b5	movl	__ZN6OSData9metaClassE,%edx
000019bb	movl	%edx,0x04(%esp)
000019bf	movl	%eax,(%esp)
000019c2	calll	__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass
000019c7	movl	(%eax),%edx
000019c9	movl	%eax,(%esp)
000019cc	call	*0x000000c4(%edx)
000019d2	movl	%eax,(%edi)
000019d4	jmpl	0x000013a0
000019d9	movl	$0x00000001,(%edi)
000019df	movl	$0xffffffff,0x04(%edi)
000019e6	jmpl	0x000013a0
000019eb	movl	$0x00000001,(%edi)
000019f1	movl	$0x00000001,0x04(%edi)
000019f8	movl	$0x0000092a,0x08(%edi)
000019ff	jmpl	0x000013a0
00001a04	movl	$0x00000001,(%edi)
00001a0a	movl	$0x00000001,0x04(%edi)
00001a11	jmpl	0x000013a0
00001a16	movl	$0xe00002bc,%eax
00001a1b	jmp	0x00001a22
00001a1d	movl	$0xe00002d5,%eax
00001a22	movl	0xf4(%ebp),%ebx
00001a25	movl	0xf8(%ebp),%esi
00001a28	movl	0xfc(%ebp),%edi
00001a2b	leave
00001a2c	ret
00001a2d	nop
__ZN20VoodooWirelessDevice25probeResponseToScanResultEN19org_voodoo_wireless13RxFrameHeaderEP6__mbufP22apple80211_scan_result:
00001a2e	pushl	%ebp
00001a2f	movl	$0xe00002c2,%eax
00001a34	movl	%esp,%ebp
00001a36	pushl	%edi
00001a37	pushl	%esi
00001a38	pushl	%ebx
00001a39	subl	$0x3c,%esp
00001a3c	movl	0x20(%ebp),%edi
00001a3f	movl	0x14(%ebp),%ebx
00001a42	movzbl	0x0c(%ebp),%esi
00001a46	testl	%edi,%edi
00001a48	jel	0x00001c03
00001a4e	movl	0x1c(%ebp),%eax
00001a51	movl	%eax,(%esp)
00001a54	calll	_mbuf_data
00001a59	movl	$0x0000008c,0x04(%esp)
00001a61	movl	%edi,(%esp)
00001a64	movl	%eax,0xe0(%ebp)
00001a67	calll	_bzero
00001a6c	movl	%esi,%edx
00001a6e	movzbl	%dl,%eax
00001a71	movl	$0x00000001,(%edi)
00001a77	movl	%eax,0x08(%edi)
00001a7a	movl	$0x00000089,0x0c(%edi)
00001a81	movl	0xe0(%ebp),%edx
00001a84	movzwl	0x20(%edx),%eax
00001a88	movw	%ax,0x14(%edi)
00001a8c	movzwl	0x22(%edx),%eax
00001a90	movw	$0xffa6,0x10(%edi)
00001a96	movw	%ax,0x16(%edi)
00001a9a	movl	0x08(%ebp),%edx
00001a9d	movl	0x0000044c(%edx),%eax
00001aa3	cmpl	$0x01,%eax
00001aa6	je	0x00001aaf
00001aa8	cmpl	$0x02,%eax
00001aab	jne	0x00001aeb
00001aad	jmp	0x00001aca
00001aaf	leal	0x88(%ebx),%eax
00001ab2	movl	$0xffffff88,%ebx
00001ab7	cmpl	$0x87,%eax
00001aba	jle	0x00001aeb
00001abc	cmpl	$0xec,%eax
00001abf	movl	%eax,%ebx
00001ac1	jle	0x00001aeb
00001ac3	movl	$0xffffffec,%ebx
00001ac8	jmp	0x00001aeb
00001aca	leal	(%ebx,%ebx,4),%eax
00001acd	movl	$0xffffff88,%ebx
00001ad2	leal	0xffffff88(,%eax,4),%eax
00001ad9	cmpl	$0x87,%eax
00001adc	jle	0x00001aeb
00001ade	movl	%eax,%ebx
00001ae0	cmpl	$0xed,%eax
00001ae3	movl	$0xffffffec,%eax
00001ae8	cmovgel	%eax,%ebx
00001aeb	movw	%bx,__ZN17IO80211Controller10monitorDLTEP16IO80211Interface(%edi)
00001aef	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000080(%edi)
00001af9	movl	0x1c(%ebp),%eax
00001afc	movl	%eax,(%esp)
00001aff	calll	_mbuf_pkthdr_len
00001b04	subl	$__ZN17IO80211Controller24hardwareOutputQueueDepthEP16IO80211Interface,%eax
00001b07	movw	%ax,0x00000084(%edi)
00001b0e	leal	0x18(%edi),%eax
00001b11	movl	%eax,0x04(%esp)
00001b15	movl	0xe0(%ebp),%eax
00001b18	movl	$0x00000006,0x08(%esp)
00001b20	addl	$0x10,%eax
00001b23	movl	%eax,(%esp)
00001b26	calll	_bcopy
00001b2b	movl	0xe0(%ebp),%esi
00001b2e	movzwl	0x00000084(%edi),%eax
00001b35	addl	$__ZN17IO80211Controller24hardwareOutputQueueDepthEP16IO80211Interface,%esi
00001b38	testw	%ax,%ax
00001b3b	jel	0x00001be9
00001b41	movzwl	%ax,%eax
00001b44	movl	%eax,(%esp)
00001b47	calll	_IOMalloc
00001b4c	movzwl	0x00000084(%edi),%edx
00001b53	movl	%eax,0x00000088(%edi)
00001b59	movl	%edx,0x08(%esp)
00001b5d	movl	%eax,0x04(%esp)
00001b61	movl	%esi,(%esp)
00001b64	calll	_bcopy
00001b69	jmp	0x00001be9
00001b6b	leal	0x02(%esi),%edx
00001b6e	movl	%edx,0xe4(%ebp)
00001b71	movzbl	(%esi),%eax
00001b74	cmpb	$0x01,%al
00001b76	je	0x00001b82
00001b78	jb	0x00001b86
00001b7a	cmpb	$0x03,%al
00001b7c	je	0x00001bb9
00001b7e	cmpb	$0x32,%al
00001b80	jne	0x00001be1
00001b82	xorl	%ebx,%ebx
00001b84	jmp	0x00001bd9
00001b86	movzbl	0x01(%esi),%eax
00001b8a	leal	0x5d(%edi),%ebx
00001b8d	movb	%al,0x5c(%edi)
00001b90	movl	$0x00000020,0x04(%esp)
00001b98	movl	%ebx,(%esp)
00001b9b	calll	_bzero
00001ba0	movzbl	0x01(%esi),%eax
00001ba4	movl	%ebx,0x04(%esp)
00001ba8	movl	%eax,0x08(%esp)
00001bac	movl	0xe4(%ebp),%eax
00001baf	movl	%eax,(%esp)
00001bb2	calll	_bcopy
00001bb7	jmp	0x00001be1
00001bb9	movzbl	0x02(%esi),%eax
00001bbd	movl	%eax,0x08(%edi)
00001bc0	jmp	0x00001be1
00001bc2	movl	0xe4(%ebp),%edx
00001bc5	movzbl	0x1e(%edi),%eax
00001bc9	movzbl	(%edx,%ebx),%edx
00001bcd	incl	%ebx
00001bce	movzbl	%al,%ecx
00001bd1	incl	%eax
00001bd2	movb	%al,0x1e(%edi)
00001bd5	movl	%edx,0x20(%edi,%ecx,4)
00001bd9	movzbl	0x01(%esi),%eax
00001bdd	cmpl	%eax,%ebx
00001bdf	jl	0x00001bc2
00001be1	movzbl	0x01(%esi),%eax
00001be5	leal	0x02(%eax,%esi),%esi
00001be9	movl	0x1c(%ebp),%eax
00001bec	movl	%eax,(%esp)
00001bef	calll	_mbuf_pkthdr_len
00001bf4	movl	%esi,%edx
00001bf6	subl	0xe0(%ebp),%edx
00001bf9	cmpl	%eax,%edx
00001bfb	jbl	0x00001b6b
00001c01	xorl	%eax,%eax
00001c03	addl	$0x3c,%esp
00001c06	popl	%ebx
00001c07	popl	%esi
00001c08	popl	%edi
00001c09	leave
00001c0a	ret
00001c0b	nop
__ZN20VoodooWirelessDevice6reportEN19org_voodoo_wireless21DeviceResponseMessageEPv:
00001c0c	pushl	%ebp
00001c0d	movl	%esp,%ebp
00001c0f	pushl	%ebx
00001c10	subl	$0x14,%esp
00001c13	movl	0x0c(%ebp),%edx
00001c16	movl	0x08(%ebp),%ebx
00001c19	movl	0x10(%ebp),%eax
00001c1c	cmpl	$0x0e,%edx
00001c1f	jal	0x00001e86
00001c25	jmp	*0x0000360c(,%edx,4)
00001c2c	movl	0x00000460(%ebx),%eax
00001c32	orl	$0x02,%eax
00001c35	andl	$0xe7,%eax
00001c38	movl	%eax,0x00000460(%ebx)
00001c3e	jmp	0x00001c47
00001c40	andl	$0xe5,0x00000460(%ebx)
00001c47	movl	0x00000474(%ebx),%eax
00001c4d	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%ebx)
00001c54	movl	(%eax),%edx
00001c56	movl	$0x00000001,0x04(%esp)
00001c5e	movl	%eax,(%esp)
00001c61	call	*0x000005d4(%edx)
00001c67	movl	(%ebx),%eax
00001c69	movl	%ebx,(%esp)
00001c6c	call	*0x00000508(%eax)
00001c72	movl	(%eax),%edx
00001c74	movl	%eax,(%esp)
00001c77	call	*0x000000a4(%edx)
00001c7d	movl	(%ebx),%eax
00001c7f	movl	%ebx,(%esp)
00001c82	call	*0x00000508(%eax)
00001c88	movl	(%eax),%edx
00001c8a	movl	%eax,(%esp)
00001c8d	call	*0x000000ac(%edx)
00001c93	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
00001c9b	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00001ca3	movl	$0x00000001,0x04(%esp)
00001cab	movl	0x00000474(%ebx),%eax
00001cb1	movl	%eax,(%esp)
00001cb4	calll	__ZN16IO80211Interface11postMessageEmPvm
00001cb9	jmpl	0x00001e86
00001cbe	andl	$0xef,0x00000460(%ebx)
00001cc5	movb	$0x02,0x00000468(%ebx)
00001ccc	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
00001cd4	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00001cdc	movl	$0x00000009,0x04(%esp)
00001ce4	movl	0x00000474(%ebx),%eax
00001cea	movl	%eax,(%esp)
00001ced	calll	__ZN16IO80211Interface11postMessageEmPvm
00001cf2	movl	0x00000474(%ebx),%eax
00001cf8	movl	(%eax),%edx
00001cfa	movl	$0x00000002,0x04(%esp)
00001d02	movl	%eax,(%esp)
00001d05	call	*0x000005d4(%edx)
00001d0b	movl	(%ebx),%eax
00001d0d	movl	%ebx,(%esp)
00001d10	call	*0x00000508(%eax)
00001d16	movl	(%eax),%edx
00001d18	movl	%eax,0x08(%ebp)
00001d1b	movl	0x000000a0(%edx),%ecx
00001d21	addl	$0x14,%esp
00001d24	popl	%ebx
00001d25	leave
00001d26	jmp	*%ecx
00001d28	andl	$0xef,0x00000460(%ebx)
00001d2f	jmp	0x00001d58
00001d31	cmpb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%ebx)
00001d38	jnel	0x00001e86
00001d3e	movb	$0x01,0x00000468(%ebx)
00001d45	jmpl	0x00001e86
00001d4a	andl	$0xef,0x00000460(%ebx)
00001d51	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%ebx)
00001d58	testl	%eax,%eax
00001d5a	je	0x00001d66
00001d5c	movl	(%eax),%eax
00001d5e	movl	%eax,0x0000046c(%ebx)
00001d64	jmp	0x00001d70
00001d66	movl	$0x00000001,0x0000046c(%ebx)
00001d70	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
00001d78	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00001d80	movl	$0x00000009,0x04(%esp)
00001d88	jmpl	0x00001cab
00001d8d	cmpb	$0x02,0x00000468(%ebx)
00001d94	sete	0x00000468(%ebx)
00001d9b	jmp	0x00001da4
00001d9d	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%ebx)
00001da4	testl	%eax,%eax
00001da6	je	0x00001db2
00001da8	movl	(%eax),%eax
00001daa	movl	%eax,0x0000046c(%ebx)
00001db0	jmp	0x00001dbc
00001db2	movl	$0x00000001,0x0000046c(%ebx)
00001dbc	movl	0x00000474(%ebx),%eax
00001dc2	movl	(%eax),%edx
00001dc4	movl	$0x00000001,0x04(%esp)
00001dcc	movl	%eax,(%esp)
00001dcf	call	*0x000005d4(%edx)
00001dd5	movl	(%ebx),%eax
00001dd7	movl	%ebx,(%esp)
00001dda	call	*0x00000508(%eax)
00001de0	movl	(%eax),%edx
00001de2	movl	%eax,(%esp)
00001de5	call	*0x000000a4(%edx)
00001deb	movl	(%ebx),%eax
00001ded	movl	%ebx,(%esp)
00001df0	call	*0x00000508(%eax)
00001df6	movl	(%eax),%edx
00001df8	movl	%eax,0x08(%ebp)
00001dfb	movl	0x000000ac(%edx),%ecx
00001e01	addl	$0x14,%esp
00001e04	popl	%ebx
00001e05	leave
00001e06	jmp	*%ecx
00001e08	andl	$0xf7,0x00000460(%ebx)
00001e0f	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
00001e17	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00001e1f	movl	$__ZN17IO80211Controller25monitorPacketHeaderLengthEP16IO80211Interface,0x04(%esp)
00001e27	jmpl	0x00001cab
00001e2c	testl	%eax,%eax
00001e2e	je	0x00001e86
00001e30	movl	(%eax),%edx
00001e32	movl	0x0000044c(%ebx),%eax
00001e38	cmpl	$0x01,%eax
00001e3b	je	0x00001e44
00001e3d	cmpl	$0x02,%eax
00001e40	jne	0x00001e80
00001e42	jmp	0x00001e5f
00001e44	leal	0x88(%edx),%eax
00001e47	movl	$0xffffff88,%edx
00001e4c	cmpl	$0x87,%eax
00001e4f	jle	0x00001e80
00001e51	cmpl	$0xec,%eax
00001e54	movl	%eax,%edx
00001e56	jle	0x00001e80
00001e58	movl	$0xffffffec,%edx
00001e5d	jmp	0x00001e80
00001e5f	leal	(%edx,%edx,4),%eax
00001e62	movl	$0xffffff88,%edx
00001e67	leal	0xffffff88(,%eax,4),%eax
00001e6e	cmpl	$0x87,%eax
00001e71	jle	0x00001e80
00001e73	movl	%eax,%edx
00001e75	cmpl	$0xed,%eax
00001e78	movl	$0xffffffec,%eax
00001e7d	cmovgel	%eax,%edx
00001e80	movl	%edx,0x000006a4(%ebx)
00001e86	addl	$0x14,%esp
00001e89	popl	%ebx
00001e8a	leave
00001e8b	ret
__ZN20VoodooWirelessDevice21handleScanResultFrameEN19org_voodoo_wireless13RxFrameHeaderEP6__mbuf:
00001e8c	pushl	%ebp
00001e8d	movl	%esp,%ebp
00001e8f	pushl	%edi
00001e90	pushl	%esi
00001e91	pushl	%ebx
00001e92	subl	$0x000000bc,%esp
00001e98	movl	0x0c(%ebp),%eax
00001e9b	movl	0x1c(%ebp),%ebx
00001e9e	leal	0xffffff5c(%ebp),%esi
00001ea4	movl	%esi,0x18(%esp)
00001ea8	movl	%eax,0x04(%esp)
00001eac	movl	0x10(%ebp),%eax
00001eaf	movl	%ebx,0x14(%esp)
00001eb3	movl	%eax,0x08(%esp)
00001eb7	movl	0x14(%ebp),%eax
00001eba	movl	%eax,0x0c(%esp)
00001ebe	movl	0x18(%ebp),%eax
00001ec1	movl	%eax,0x10(%esp)
00001ec5	movl	0x08(%ebp),%eax
00001ec8	movl	%eax,(%esp)
00001ecb	calll	__ZN20VoodooWirelessDevice25probeResponseToScanResultEN19org_voodoo_wireless13RxFrameHeaderEP6__mbufP22apple80211_scan_result
00001ed0	movl	0x08(%ebp),%edx
00001ed3	movl	(%edx),%eax
00001ed5	movl	%edx,(%esp)
00001ed8	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00001ee0	movl	%ebx,0x04(%esp)
00001ee4	call	*0x00000520(%eax)
00001eea	movl	%esi,(%esp)
00001eed	movl	$0x0000008c,0x04(%esp)
00001ef5	calll	__ZN6OSData9withBytesEPKvj
00001efa	testl	%eax,%eax
00001efc	movl	%eax,%esi
00001efe	jel	0x00001ff6
00001f04	xorl	%edi,%edi
00001f06	jmp	0x00001f66
00001f08	movl	0x08(%ebp),%edx
00001f0b	movl	0x00000484(%edx),%eax
00001f11	movl	(%eax),%edx
00001f13	movl	%edi,0x04(%esp)
00001f17	movl	%eax,(%esp)
00001f1a	call	*0x000000fc(%edx)
00001f20	movl	__ZN6OSData9metaClassE,%edx
00001f26	movl	%edx,0x04(%esp)
00001f2a	movl	%eax,(%esp)
00001f2d	calll	__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass
00001f32	movl	(%eax),%edx
00001f34	movl	%eax,(%esp)
00001f37	call	*0x000000c4(%edx)
00001f3d	movl	%eax,%ebx
00001f3f	movl	(%esi),%eax
00001f41	movl	%esi,(%esp)
00001f44	call	*0x000000c4(%eax)
00001f4a	movl	%ebx,0x04(%esp)
00001f4e	movl	%eax,0x08(%esp)
00001f52	movl	0x08(%ebp),%eax
00001f55	movl	%eax,(%esp)
00001f58	calll	__ZN20VoodooWirelessDevice21scanResultsAreSimilarEPK22apple80211_scan_resultS2_
00001f5d	testb	%al,%al
00001f5f	jnel	0x00001fee
00001f65	incl	%edi
00001f66	movl	0x08(%ebp),%edx
00001f69	movl	0x00000484(%edx),%eax
00001f6f	movl	(%eax),%edx
00001f71	movl	%eax,(%esp)
00001f74	call	*0x000000a0(%edx)
00001f7a	cmpl	%edi,%eax
00001f7c	ja	0x00001f08
00001f7e	movl	0x08(%ebp),%edx
00001f81	movl	0x00000484(%edx),%eax
00001f87	movl	(%eax),%edx
00001f89	movl	%esi,0x04(%esp)
00001f8d	movl	%eax,(%esp)
00001f90	call	*0x000000e4(%edx)
00001f96	movl	0x08(%ebp),%edx
00001f99	movl	0x00000484(%edx),%eax
00001f9f	movl	(%eax),%edx
00001fa1	movl	%eax,(%esp)
00001fa4	call	*0x000000a0(%edx)
00001faa	movl	0x08(%ebp),%edx
00001fad	movl	%eax,0x0000048c(%edx)
00001fb3	movl	0x00000488(%edx),%eax
00001fb9	incl	%eax
00001fba	cmpl	$__ZN17IO80211Controller13enableFeatureE18IO80211FeatureCodePv,%eax
00001fbd	movl	%eax,0x00000488(%edx)
00001fc3	jbe	0x00001fee
00001fc5	movl	0x08(%ebp),%edx
00001fc8	movl	(%edx),%eax
00001fca	movl	%edx,(%esp)
00001fcd	call	*0x00000744(%eax)
00001fd3	movl	0x08(%ebp),%eax
00001fd6	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00001fde	movl	$0x00000005,0x04(%esp)
00001fe6	movl	%eax,(%esp)
00001fe9	calll	__ZN20VoodooWirelessDevice6reportEN19org_voodoo_wireless21DeviceResponseMessageEPv
00001fee	movl	(%esi),%eax
00001ff0	movl	%esi,(%esp)
00001ff3	call	*0x1c(%eax)
00001ff6	addl	$0x000000bc,%esp
00001ffc	popl	%ebx
00001ffd	popl	%esi
00001ffe	popl	%edi
00001fff	leave
00002000	ret
00002001	nop
__ZN20VoodooWirelessDevice10inputFrameEN19org_voodoo_wireless13RxFrameHeaderEP6__mbuf:
00002002	pushl	%ebp
00002003	movl	%esp,%ebp
00002005	pushl	%edi
00002006	pushl	%esi
00002007	pushl	%ebx
00002008	subl	$0x3c,%esp
0000200b	movl	0x1c(%ebp),%eax
0000200e	movl	0x08(%ebp),%esi
00002011	movl	%eax,(%esp)
00002014	calll	_mbuf_data
00002019	movl	$0x00000010,0x08(%esp)
00002021	movl	%eax,%edi
00002023	leal	0x000006ac(%esi),%eax
00002029	movl	%eax,0x04(%esp)
0000202d	leal	0x0c(%ebp),%eax
00002030	movl	%eax,(%esp)
00002033	calll	_bcopy
00002038	movl	0x0000044c(%esi),%eax
0000203e	movl	0x14(%ebp),%ecx
00002041	movl	0x000006a8(%esi),%ebx
00002047	cmpl	$0x01,%eax
0000204a	movl	%ecx,%edx
0000204c	je	0x00002055
0000204e	cmpl	$0x02,%eax
00002051	jne	0x00002091
00002053	jmp	0x00002070
00002055	leal	0x88(%ecx),%eax
00002058	movl	$0xffffff88,%edx
0000205d	cmpl	$0x87,%eax
00002060	jle	0x00002091
00002062	cmpl	$0xec,%eax
00002065	movl	%eax,%edx
00002067	jle	0x00002091
00002069	movl	$0xffffffec,%edx
0000206e	jmp	0x00002091
00002070	leal	(%ecx,%ecx,4),%eax
00002073	movl	$0xffffff88,%edx
00002078	leal	0xffffff88(,%eax,4),%eax
0000207f	cmpl	$0x87,%eax
00002082	jle	0x00002091
00002084	movl	%eax,%edx
00002086	cmpl	$0xed,%eax
00002089	movl	$0xffffffec,%eax
0000208e	cmovgel	%eax,%edx
00002091	leal	(%edx,%ebx),%eax
00002094	movl	%eax,%edx
00002096	shrl	$0x1f,%edx
00002099	addl	%eax,%edx
0000209b	sarl	%edx
0000209d	movl	%edx,0x000006a8(%esi)
000020a3	movzbl	(%edi),%edx
000020a6	movl	%edx,%eax
000020a8	andl	$0x0c,%eax
000020ab	cmpb	$0x08,%al
000020ad	jnel	0x00002144
000020b3	movl	0x1c(%ebp),%edx
000020b6	movl	%edx,(%esp)
000020b9	calll	_mbuf_len
000020be	cmpl	$0x20,%eax
000020c1	jbel	0x0000218a
000020c7	leal	0xe0(%ebp),%eax
000020ca	movl	%eax,0x04(%esp)
000020ce	leal	0x10(%edi),%eax
000020d1	leal	__ZN20VoodooWirelessDeviceD0Ev(%ebp),%ebx
000020d4	movl	%eax,(%esp)
000020d7	movl	$0x00000006,0x08(%esp)
000020df	calll	_bcopy
000020e4	leal	0x04(%edi),%eax
000020e7	movl	%eax,(%esp)
000020ea	movl	$0x00000006,0x08(%esp)
000020f2	movl	%ebx,0x04(%esp)
000020f6	calll	_bcopy
000020fb	movl	0x1c(%ebp),%eax
000020fe	movl	%eax,(%esp)
00002101	calll	_mbuf_data
00002106	movl	$0x0000000c,0x08(%esp)
0000210e	movl	%ebx,(%esp)
00002111	addl	$__ZN17IO80211Controller10monitorDLTEP16IO80211Interface,%eax
00002114	movl	%eax,0x04(%esp)
00002118	calll	_bcopy
0000211d	movl	0x1c(%ebp),%edx
00002120	movl	$__ZN17IO80211Controller10monitorDLTEP16IO80211Interface,0x04(%esp)
00002128	movl	%edx,(%esp)
0000212b	calll	_mbuf_adj
00002130	movl	(%esi),%eax
00002132	movl	0x1c(%ebp),%edx
00002135	movl	%esi,(%esp)
00002138	movl	%edx,0x04(%esp)
0000213c	call	*0x000006e0(%eax)
00002142	jmp	0x000021a4
00002144	testb	$0x08,0x00000460(%esi)
0000214b	je	0x0000218a
0000214d	movl	%edx,%eax
0000214f	andl	$0xfc,%eax
00002152	cmpb	$0x50,%al
00002154	sete	%dl
00002157	cmpb	$0x80,%al
00002159	sete	%al
0000215c	orb	%al,%dl
0000215e	je	0x0000218a
00002160	movl	0x1c(%ebp),%eax
00002163	movl	%ecx,0x0c(%esp)
00002167	movl	%esi,(%esp)
0000216a	movl	%eax,0x14(%esp)
0000216e	movl	0x0c(%ebp),%eax
00002171	movl	%eax,0x04(%esp)
00002175	movl	0x10(%ebp),%eax
00002178	movl	%eax,0x08(%esp)
0000217c	movl	0x18(%ebp),%eax
0000217f	movl	%eax,0x10(%esp)
00002183	calll	__ZN20VoodooWirelessDevice21handleScanResultFrameEN19org_voodoo_wireless13RxFrameHeaderEP6__mbuf
00002188	jmp	0x000021a4
0000218a	movl	(%esi),%eax
0000218c	movl	0x1c(%ebp),%edx
0000218f	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00002197	movl	%esi,(%esp)
0000219a	movl	%edx,0x04(%esp)
0000219e	call	*0x00000520(%eax)
000021a4	addl	$0x3c,%esp
000021a7	popl	%ebx
000021a8	popl	%esi
000021a9	popl	%edi
000021aa	leave
000021ab	ret
__ZN20VoodooWirelessDevice21apple80211Request_SETEiPv:
000021ac	pushl	%ebp
000021ad	movl	%esp,%ebp
000021af	subl	$0x000000f8,%esp
000021b5	movl	0x0c(%ebp),%eax
000021b8	movl	%ebx,0xf4(%ebp)
000021bb	movl	%esi,0xf8(%ebp)
000021be	movl	%edi,0xfc(%ebp)
000021c1	subl	$0x06,%eax
000021c4	cmpl	$0x1e,%eax
000021c7	ja	0x000021d0
000021c9	jmp	*0x00003648(,%eax,4)
000021d0	movl	$0xe00002c7,%eax
000021d5	jmpl	0x0000277a
000021da	movl	0x10(%ebp),%edx
000021dd	movl	0x08(%edx),%eax
000021e0	testl	%eax,%eax
000021e2	jel	0x000022a7
000021e8	decl	%eax
000021e9	jnel	0x000022d0
000021ef	movl	0x08(%ebp),%ecx
000021f2	testb	$0x02,0x00000460(%ecx)
000021f9	jnel	0x000022d0
000021ff	movl	(%ecx),%eax
00002201	movl	%ecx,(%esp)
00002204	call	*0x00000738(%eax)
0000220a	testl	%eax,%eax
0000220c	je	0x0000221a
0000220e	movl	$0x000038b8,(%esp)
00002215	jmpl	0x000022cb
0000221a	movl	0x08(%ebp),%edx
0000221d	movl	0x00000460(%edx),%eax
00002223	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%edx)
0000222a	andl	$0xe7,%eax
0000222d	orl	$0x02,%eax
00002230	movl	%eax,0x00000460(%edx)
00002236	movl	0x00000474(%edx),%eax
0000223c	movl	(%eax),%edx
0000223e	movl	$0x00000001,0x04(%esp)
00002246	movl	%eax,(%esp)
00002249	call	*0x000005d4(%edx)
0000224f	movl	0x08(%ebp),%ecx
00002252	movl	(%ecx),%eax
00002254	movl	%ecx,(%esp)
00002257	call	*0x00000508(%eax)
0000225d	movl	(%eax),%edx
0000225f	movl	%eax,(%esp)
00002262	call	*0x000000a4(%edx)
00002268	movl	0x08(%ebp),%edx
0000226b	movl	(%edx),%eax
0000226d	movl	%edx,(%esp)
00002270	call	*0x00000508(%eax)
00002276	movl	(%eax),%edx
00002278	movl	%eax,(%esp)
0000227b	call	*0x000000ac(%edx)
00002281	movl	0x08(%ebp),%ecx
00002284	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
0000228c	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00002294	movl	$0x00000001,0x04(%esp)
0000229c	movl	0x00000474(%ecx),%eax
000022a2	jmpl	0x00002357
000022a7	movl	0x08(%ebp),%eax
000022aa	testb	$0x02,0x00000460(%eax)
000022b1	je	0x000022d0
000022b3	movl	%eax,%edx
000022b5	movl	(%eax),%eax
000022b7	movl	%edx,(%esp)
000022ba	call	*0x0000073c(%eax)
000022c0	testl	%eax,%eax
000022c2	je	0x000022da
000022c4	movl	$0x000038ec,(%esp)
000022cb	calll	_IOLog
000022d0	movl	$0xe00002bc,%eax
000022d5	jmpl	0x0000277a
000022da	movl	0x08(%ebp),%ecx
000022dd	movl	0x00000474(%ecx),%eax
000022e3	andl	$0xe5,0x00000460(%ecx)
000022ea	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%ecx)
000022f1	movl	(%eax),%edx
000022f3	movl	$0x00000001,0x04(%esp)
000022fb	movl	%eax,(%esp)
000022fe	call	*0x000005d4(%edx)
00002304	movl	0x08(%ebp),%edx
00002307	movl	(%edx),%eax
00002309	movl	%edx,(%esp)
0000230c	call	*0x00000508(%eax)
00002312	movl	(%eax),%edx
00002314	movl	%eax,(%esp)
00002317	call	*0x000000a4(%edx)
0000231d	movl	0x08(%ebp),%ecx
00002320	movl	(%ecx),%eax
00002322	movl	%ecx,(%esp)
00002325	call	*0x00000508(%eax)
0000232b	movl	(%eax),%edx
0000232d	movl	%eax,(%esp)
00002330	call	*0x000000ac(%edx)
00002336	movl	0x08(%ebp),%edx
00002339	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x0c(%esp)
00002341	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
00002349	movl	$0x00000001,0x04(%esp)
00002351	movl	0x00000474(%edx),%eax
00002357	movl	%eax,(%esp)
0000235a	calll	__ZN16IO80211Interface11postMessageEmPvm
0000235f	jmpl	0x00002778
00002364	movl	0x08(%ebp),%ecx
00002367	movl	0x00000460(%ecx),%eax
0000236d	testb	$0x08,%al
0000236f	jnel	0x00002771
00002375	testb	$0x10,%al
00002377	jnel	0x00002771
0000237d	movl	0x10(%ebp),%eax
00002380	cmpl	$0x03,0x34(%eax)
00002384	jel	0x00002778
0000238a	leal	0xffffff30(%ebp),%edi
00002390	movl	$0x0000001c,0x04(%esp)
00002398	movl	%edi,(%esp)
0000239b	calll	_bzero
000023a0	movl	0x10(%ebp),%edx
000023a3	movl	0x34(%edx),%eax
000023a6	movl	%eax,0xffffff30(%ebp)
000023ac	movl	0x38(%edx),%eax
000023af	movl	%eax,0xffffff34(%ebp)
000023b5	movzwl	0x3c(%edx),%edx
000023b9	movl	$0x000000c8,%eax
000023be	movzwl	%dx,%ecx
000023c1	testw	%dx,%dx
000023c4	movl	0x10(%ebp),%edx
000023c7	cmovnel	%ecx,%eax
000023ca	movl	%eax,0xffffff44(%ebp)
000023d0	movl	__ZN17IO80211Controller13enableFeatureE18IO80211FeatureCodePv(%edx),%eax
000023d3	movl	$0x00000032,%edx
000023d8	movl	$0x00000006,0x08(%esp)
000023e0	testl	%eax,%eax
000023e2	cmovel	%edx,%eax
000023e5	movl	%eax,0xffffff48(%ebp)
000023eb	leal	0xffffff38(%ebp),%eax
000023f1	movl	%eax,0x04(%esp)
000023f5	movl	0x10(%ebp),%eax
000023f8	addl	$0x08,%eax
000023fb	movl	%eax,(%esp)
000023fe	calll	_bcopy
00002403	movl	0x10(%ebp),%ecx
00002406	movl	0x10(%ecx),%eax
00002409	testl	%eax,%eax
0000240b	je	0x00002420
0000240d	movl	%eax,0x04(%esp)
00002411	movl	%ecx,%eax
00002413	addl	$0x14,%eax
00002416	movl	%eax,(%esp)
00002419	calll	__ZN6OSData15withBytesNoCopyEPvj
0000241e	jmp	0x0000242c
00002420	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,(%esp)
00002427	calll	__ZN6OSData12withCapacityEj
0000242c	movl	%eax,0xffffff40(%ebp)
00002432	movl	0x08(%ebp),%eax
00002435	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000488(%eax)
0000243f	movl	0x08(%ebp),%edx
00002442	movl	0x08(%ebp),%ecx
00002445	movl	(%edx),%eax
00002447	addl	$0x000002c0,%edx
0000244d	movl	%edx,0x08(%esp)
00002451	movl	%edi,0x04(%esp)
00002455	movl	%ecx,(%esp)
00002458	call	*0x00000740(%eax)
0000245e	testl	%eax,%eax
00002460	jnel	0x000022d0
00002466	movl	0x08(%ebp),%edx
00002469	movl	0x00000484(%edx),%eax
0000246f	movl	(%eax),%edx
00002471	movl	%eax,(%esp)
00002474	call	*0x000000b4(%edx)
0000247a	movl	0x08(%ebp),%ecx
0000247d	orl	$0x08,0x00000460(%ecx)
00002484	jmpl	0x00002778
00002489	movl	0x08(%ebp),%eax
0000248c	cmpb	$0x02,0x00000468(%eax)
00002493	jel	0x00002771
00002499	movl	%eax,%edx
0000249b	movl	0x00000460(%eax),%eax
000024a1	testb	$0x10,%al
000024a3	jnel	0x00002771
000024a9	testb	$0x08,%al
000024ab	je	0x000024d3
000024ad	movl	(%edx),%eax
000024af	movl	%edx,(%esp)
000024b2	call	*0x00000744(%eax)
000024b8	movl	0x08(%ebp),%ecx
000024bb	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x08(%esp)
000024c3	movl	$0x00000005,0x04(%esp)
000024cb	movl	%ecx,(%esp)
000024ce	calll	__ZN20VoodooWirelessDevice6reportEN19org_voodoo_wireless21DeviceResponseMessageEPv
000024d3	movl	0x10(%ebp),%eax
000024d6	movl	0x08(%ebp),%edx
000024d9	movl	%eax,0x04(%esp)
000024dd	movl	%edx,(%esp)
000024e0	calll	__ZN20VoodooWirelessDevice14findScanResultEP21apple80211_assoc_data
000024e5	testl	%eax,%eax
000024e7	movl	%eax,%ebx
000024e9	jel	0x000022d0
000024ef	leal	0xffffff30(%ebp),%edi
000024f5	movl	$0x000000b8,0x04(%esp)
000024fd	leal	0xffffff44(%ebp),%esi
00002503	movl	%edi,(%esp)
00002506	calll	_bzero
0000250b	leal	0xffffff34(%ebp),%ecx
00002511	leal	0x18(%ebx),%eax
00002514	movl	%ecx,0xffffff24(%ebp)
0000251a	movl	%ecx,0x04(%esp)
0000251e	movl	%eax,(%esp)
00002521	movl	$0x00000006,0x08(%esp)
00002529	calll	_bcopy
0000252e	movzbl	0x5c(%ebx),%eax
00002532	movl	%eax,0x04(%esp)
00002536	leal	0x5d(%ebx),%eax
00002539	movl	%eax,(%esp)
0000253c	calll	__ZN6OSData9withBytesEPKvj
00002541	movl	%ebx,%edx
00002543	xorl	%ecx,%ecx
00002545	movl	%eax,0xffffff30(%ebp)
0000254b	movl	0x08(%ebx),%eax
0000254e	movb	%al,0xffffff3a(%ebp)
00002554	movl	0x0c(%ebx),%eax
00002557	movw	%ax,0xffffff3c(%ebp)
0000255e	movzwl	0x16(%ebx),%eax
00002562	movw	%ax,0xffffff3e(%ebp)
00002569	movzbl	0x1e(%ebx),%eax
0000256d	movl	%eax,0xffffff40(%ebp)
00002573	jmp	0x0000257e
00002575	movl	0x1c(%edx),%eax
00002578	incl	%ecx
00002579	movl	%eax,(%esi)
0000257b	addl	$0x04,%esi
0000257e	movzbl	0x1e(%ebx),%eax
00002582	addl	$0x04,%edx
00002585	cmpl	%eax,%ecx
00002587	jl	0x00002575
00002589	movzwl	0x14(%ebx),%eax
0000258d	movl	0x10(%ebp),%edx
00002590	movl	$0xffffffa6,0xc8(%ebp)
00002597	movl	%eax,0xc4(%ebp)
0000259a	movswl	__ZN17IO80211Controller10monitorDLTEP16IO80211Interface(%ebx),%eax
0000259e	movl	%edx,%ecx
000025a0	movl	%eax,0xcc(%ebp)
000025a3	movzwl	0x04(%edx),%eax
000025a7	movl	%eax,0xd0(%ebp)
000025aa	movzwl	0x06(%ecx),%eax
000025ae	movzwl	0x08(%edx),%edx
000025b2	decl	%eax
000025b3	addl	%edx,%edx
000025b5	orl	%eax,%edx
000025b7	movl	$0x00000001,%eax
000025bc	movl	%edx,0xd4(%ebp)
000025bf	movzbl	0xe4(%ebp),%edx
000025c3	testb	$0x01,0x00000180(%ecx)
000025ca	movl	%ecx,(%esp)
000025cd	movl	$0x00000184,0x08(%esp)
000025d5	cmovel	%edx,%eax
000025d8	movb	%al,0xe4(%ebp)
000025db	movl	0x08(%ebp),%eax
000025de	addl	$0x0000051c,%eax
000025e3	movl	%eax,0x04(%esp)
000025e7	calll	_bcopy
000025ec	movl	0x08(%ebp),%eax
000025ef	movl	$0x00000006,0x08(%esp)
000025f7	addl	$0x0000054c,%eax
000025fc	movl	%eax,0x04(%esp)
00002600	movl	0xffffff24(%ebp),%eax
00002606	movl	%eax,(%esp)
00002609	calll	_bcopy
0000260e	movl	0x08(%ebp),%eax
00002611	movl	$0x0000008c,0x08(%esp)
00002619	movl	%ebx,(%esp)
0000261c	addl	$0x00000490,%eax
00002621	movl	%eax,0x04(%esp)
00002625	calll	_bcopy
0000262a	movl	0x08(%ebp),%edx
0000262d	movl	(%edx),%eax
0000262f	movl	%edi,0x04(%esp)
00002633	movl	%edx,(%esp)
00002636	call	*0x00000748(%eax)
0000263c	testl	%eax,%eax
0000263e	jnel	0x000022d0
00002644	movl	0x08(%ebp),%ecx
00002647	orl	$0x10,0x00000460(%ecx)
0000264e	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%ecx)
00002655	jmpl	0x0000277a
0000265a	movl	0x08(%ebp),%edx
0000265d	movl	0x00000460(%edx),%eax
00002663	testb	$0x08,%al
00002665	jnel	0x00002771
0000266b	testb	$0x10,%al
0000266d	jnel	0x00002771
00002673	movl	0x10(%ebp),%eax
00002676	movl	%edx,%ecx
00002678	movl	(%edx),%edx
0000267a	movl	$0x00000002,0x04(%esp)
00002682	addl	$0x04,%eax
00002685	movl	%eax,0x08(%esp)
00002689	jmpl	0x00002766
0000268e	movl	0x08(%ebp),%edx
00002691	movl	0x00000460(%edx),%eax
00002697	testb	$0x08,%al
00002699	jnel	0x00002771
0000269f	testb	$0x10,%al
000026a1	jnel	0x00002771
000026a7	movl	0x10(%ebp),%ecx
000026aa	movl	0x04(%ecx),%edx
000026ad	testl	%edx,%edx
000026af	jne	0x000026b8
000026b1	movl	$0x0000092a,0x08(%ecx)
000026b8	movl	0x08(%ebp),%eax
000026bb	movl	0x08(%ebp),%ecx
000026be	movl	(%eax),%edx
000026c0	movl	0x10(%ebp),%eax
000026c3	movl	$0x00000001,0x04(%esp)
000026cb	addl	$0x08,%eax
000026ce	movl	%eax,0x08(%esp)
000026d2	jmpl	0x00002766
000026d7	movl	0x08(%ebp),%edx
000026da	movl	0x00000460(%edx),%eax
000026e0	testb	$0x08,%al
000026e2	jnel	0x00002771
000026e8	testb	$0x10,%al
000026ea	jnel	0x00002771
000026f0	movl	(%edx),%eax
000026f2	movl	%edx,(%esp)
000026f5	call	*0x0000074c(%eax)
000026fb	testl	%eax,%eax
000026fd	jnel	0x000022d0
00002703	movl	0x08(%ebp),%ecx
00002706	andl	$0xef,0x00000460(%ecx)
0000270d	movb	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x00000468(%ecx)
00002714	jmp	0x0000277a
00002716	movl	0x08(%ebp),%edx
00002719	movl	0x00000460(%edx),%eax
0000271f	testb	$0x08,%al
00002721	jne	0x00002771
00002723	testb	$0x10,%al
00002725	jne	0x00002771
00002727	movl	0x10(%ebp),%eax
0000272a	movl	%edx,%ecx
0000272c	movl	(%edx),%edx
0000272e	movl	$0x00000003,0x04(%esp)
00002736	addl	$0x04,%eax
00002739	movl	%eax,0x08(%esp)
0000273d	jmp	0x00002766
0000273f	movl	0x08(%ebp),%edx
00002742	movl	0x00000460(%edx),%eax
00002748	testb	$0x08,%al
0000274a	jne	0x00002771
0000274c	testb	$0x10,%al
0000274e	jne	0x00002771
00002750	movl	0x10(%ebp),%eax
00002753	movl	%edx,%ecx
00002755	movl	(%edx),%edx
00002757	movl	$0x00000004,0x04(%esp)
0000275f	addl	$0x04,%eax
00002762	movl	%eax,0x08(%esp)
00002766	movl	%ecx,(%esp)
00002769	call	*0x00000758(%edx)
0000276f	jmp	0x0000277a
00002771	movl	$0xe00002d5,%eax
00002776	jmp	0x0000277a
00002778	xorl	%eax,%eax
0000277a	movl	0xf4(%ebp),%ebx
0000277d	movl	0xf8(%ebp),%esi
00002780	movl	0xfc(%ebp),%edi
00002783	leave
00002784	ret
00002785	nop
__ZN20VoodooWirelessDevice17apple80211RequestEmiP16IO80211InterfacePv:
00002786	pushl	%ebp
00002787	movl	%esp,%ebp
00002789	cmpl	$0xc02069c9,0x0c(%ebp)
00002790	movl	0x08(%ebp),%ecx
00002793	movl	0x10(%ebp),%edx
00002796	movl	0x18(%ebp),%eax
00002799	jne	0x000027a7
0000279b	movl	%eax,0x10(%ebp)
0000279e	movl	%edx,0x0c(%ebp)
000027a1	leave
000027a2	jmpl	__ZN20VoodooWirelessDevice21apple80211Request_GETEiPv
000027a7	movl	%eax,0x10(%ebp)
000027aa	movl	%edx,0x0c(%ebp)
000027ad	movl	%ecx,0x08(%ebp)
000027b0	leave
000027b1	jmpl	__ZN20VoodooWirelessDevice21apple80211Request_SETEiPv
__ZN20VoodooWirelessDevice9MetaClassD1Ev:
000027b6	pushl	%ebp
000027b7	movl	%esp,%ebp
000027b9	pushl	%ebx
000027ba	subl	$0x14,%esp
000027bd	movl	0x08(%ebp),%ebx
000027c0	movl	$__ZTVN20VoodooWirelessDevice9MetaClassE,(%ebx)
000027c6	movl	%ebx,(%esp)
000027c9	calll	__ZN11OSMetaClassD2Ev
000027ce	movl	%ebx,%eax
000027d0	addl	$0x14,%esp
000027d3	popl	%ebx
000027d4	leave
000027d5	ret
__ZN19org_voodoo_wireless6IEListC2Ev:
000027d6	pushl	%ebp
000027d7	movl	%esp,%ebp
000027d9	movl	0x08(%ebp),%eax
000027dc	movl	$__ZTVN19org_voodoo_wireless6IEListE,(%eax)
000027e2	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x04(%eax)
000027e9	leave
000027ea	ret
000027eb	nop
__ZN19org_voodoo_wireless6IEListC1Ev:
000027ec	pushl	%ebp
000027ed	movl	%esp,%ebp
000027ef	movl	0x08(%ebp),%eax
000027f2	movl	$__ZTVN19org_voodoo_wireless6IEListE,(%eax)
000027f8	movl	$__ZN17IO80211Controller20outputRaw80211PacketEP16IO80211InterfaceP6__mbuf,0x04(%eax)
000027ff	leave
00002800	ret
00002801	nop
__ZN19org_voodoo_wireless6IEListD2Ev:
00002802	pushl	%ebp
00002803	movl	%esp,%ebp
00002805	pushl	%ebx
00002806	subl	$0x14,%esp
00002809	movl	0x08(%ebp),%ebx
0000280c	movl	0x04(%ebx),%edx
0000280f	movl	$__ZTVN19org_voodoo_wireless6IEListE,(%ebx)
00002815	testl	%edx,%edx
00002817	je	0x00002821
00002819	movl	(%edx),%eax
0000281b	movl	%edx,(%esp)
0000281e	call	*0x1c(%eax)
00002821	movl	%ebx,%eax
00002823	addl	$0x14,%esp
00002826	popl	%ebx
00002827	leave
00002828	ret
00002829	nop
__ZN19org_voodoo_wireless6IEListD1Ev:
0000282a	pushl	%ebp
0000282b	movl	%esp,%ebp
0000282d	pushl	%ebx
0000282e	subl	$0x14,%esp
00002831	movl	0x08(%ebp),%ebx
00002834	movl	0x04(%ebx),%edx
00002837	movl	$__ZTVN19org_voodoo_wireless6IEListE,(%ebx)
0000283d	testl	%edx,%edx
0000283f	je	0x00002849
00002841	movl	(%edx),%eax
00002843	movl	%edx,(%esp)
00002846	call	*0x1c(%eax)
00002849	movl	%ebx,%eax
0000284b	addl	$0x14,%esp
0000284e	popl	%ebx
0000284f	leave
00002850	ret
00002851	nop
__ZN19org_voodoo_wireless6IEListD0Ev:
00002852	pushl	%ebp
00002853	movl	%esp,%ebp
00002855	pushl	%ebx
00002856	subl	$0x14,%esp
00002859	movl	0x08(%ebp),%ebx
0000285c	movl	0x04(%ebx),%edx
0000285f	movl	$__ZTVN19org_voodoo_wireless6IEListE,(%ebx)
00002865	testl	%edx,%edx
00002867	je	0x00002871
00002869	movl	(%edx),%eax
0000286b	movl	%edx,(%esp)
0000286e	call	*0x1c(%eax)
00002871	movl	%ebx,(%esp)
00002874	calll	__ZdlPv
00002879	movl	%ebx,%eax
0000287b	addl	$0x14,%esp
0000287e	popl	%ebx
0000287f	leave
00002880	ret
00002881	nop
__ZN19org_voodoo_wireless6IEList3getENS_4IEEE2IE2IDE:
00002882	pushl	%ebp
00002883	movl	%esp,%ebp
00002885	subl	$0x38,%esp
00002888	movl	%esi,0xf8(%ebp)
0000288b	movl	0x08(%ebp),%esi
0000288e	movl	%edi,0xfc(%ebp)
00002891	movl	0x0c(%ebp),%edi
00002894	movl	%ebx,0xf4(%ebp)
00002897	movl	0x04(%esi),%edx
0000289a	testl	%edx,%edx
0000289c	je	0x000028ed
0000289e	movl	(%edx),%eax
000028a0	xorl	%ebx,%ebx
000028a2	movl	%edx,(%esp)
000028a5	call	*0x000000c4(%eax)
000028ab	movl	%eax,0xe4(%ebp)
000028ae	jmp	0x000028db
000028b0	movl	0xe4(%ebp),%edx
000028b3	addl	%ebx,%edx
000028b5	movzbl	(%edx),%eax
000028b8	cmpl	%edi,%eax
000028ba	jne	0x000028d5
000028bc	movzbl	0x01(%edx),%eax
000028c0	movl	0xf4(%ebp),%ebx
000028c3	movl	%edx,0x08(%ebp)
000028c6	movl	0xf8(%ebp),%esi
000028c9	movl	0xfc(%ebp),%edi
000028cc	movl	%eax,0x0c(%ebp)
000028cf	leave
000028d0	jmpl	__ZN6OSData9withBytesEPKvj
000028d5	movzbl	0x01(%edx),%eax
000028d9	addl	%eax,%ebx
000028db	movl	0x04(%esi),%eax
000028de	movl	(%eax),%edx
000028e0	movl	%eax,(%esp)
000028e3	call	*0x000000a8(%edx)
000028e9	cmpl	%eax,%ebx
000028eb	jb	0x000028b0
000028ed	movl	0xf4(%ebp),%ebx
000028f0	xorl	%eax,%eax
000028f2	movl	0xf8(%ebp),%esi
000028f5	movl	0xfc(%ebp),%edi
000028f8	leave
000028f9	ret
__ZN19org_voodoo_wireless6IEList12getRawAsDataEv:
000028fa	pushl	%ebp
000028fb	movl	%esp,%ebp
000028fd	movl	0x08(%ebp),%eax
00002900	movl	0x04(%eax),%eax
00002903	testl	%eax,%eax
00002905	je	0x00002910
00002907	movl	%eax,0x08(%ebp)
0000290a	leave
0000290b	jmpl	__ZN6OSData8withDataEPKS_
00002910	leave
00002911	xorl	%eax,%eax
00002913	ret
__ZN19org_voodoo_wireless6IEList8withDataEP6OSData:
00002914	pushl	%ebp
00002915	movl	%esp,%ebp
00002917	subl	$0x18,%esp
0000291a	movl	$0x00000008,(%esp)
00002921	movl	%ebx,0xf8(%ebp)
00002924	movl	%esi,0xfc(%ebp)
00002927	movl	0x08(%ebp),%esi
0000292a	calll	__Znwm
0000292f	testl	%eax,%eax
00002931	movl	%eax,%ebx
00002933	je	0x00002946
00002935	movl	$__ZTVN19org_voodoo_wireless6IEListE,(%eax)
0000293b	movl	%esi,0x04(%eax)
0000293e	movl	(%esi),%eax
00002940	movl	%esi,(%esp)
00002943	call	*0x18(%eax)
00002946	movl	%ebx,%eax
00002948	movl	0xfc(%ebp),%esi
0000294b	movl	0xf8(%ebp),%ebx
0000294e	leave
0000294f	ret
__ZN21VoodooWirelessCommandC2EPK11OSMetaClass:
00002950	pushl	%ebp
00002951	movl	%esp,%ebp
00002953	pushl	%ebx
00002954	subl	$0x14,%esp
00002957	movl	0x08(%ebp),%ebx
0000295a	movl	0x0c(%ebp),%eax
0000295d	movl	%ebx,(%esp)
00002960	movl	%eax,0x04(%esp)
00002964	calll	__ZN9IOCommandC2EPK11OSMetaClass
00002969	movl	%ebx,%eax
0000296b	movl	$__ZTV21VoodooWirelessCommand,(%ebx)
00002971	addl	$0x14,%esp
00002974	popl	%ebx
00002975	leave
00002976	ret
00002977	nop
__ZN21VoodooWirelessCommandC1EPK11OSMetaClass:
00002978	pushl	%ebp
00002979	movl	%esp,%ebp
0000297b	pushl	%ebx
0000297c	subl	$0x14,%esp
0000297f	movl	0x08(%ebp),%ebx
00002982	movl	0x0c(%ebp),%eax
00002985	movl	%ebx,(%esp)
00002988	movl	%eax,0x04(%esp)
0000298c	calll	__ZN9IOCommandC2EPK11OSMetaClass
00002991	movl	%ebx,%eax
00002993	movl	$__ZTV21VoodooWirelessCommand,(%ebx)
00002999	addl	$0x14,%esp
0000299c	popl	%ebx
0000299d	leave
0000299e	ret
0000299f	nop
__ZN21VoodooWirelessCommandD2Ev:
000029a0	pushl	%ebp
000029a1	movl	%esp,%ebp
000029a3	pushl	%ebx
000029a4	subl	$0x14,%esp
000029a7	movl	0x08(%ebp),%ebx
000029aa	movl	$__ZTV21VoodooWirelessCommand,(%ebx)
000029b0	movl	%ebx,(%esp)
000029b3	calll	__ZN9IOCommandD2Ev
000029b8	movl	%ebx,%eax
000029ba	addl	$0x14,%esp
000029bd	popl	%ebx
000029be	leave
000029bf	ret
__ZN21VoodooWirelessCommandD1Ev:
000029c0	pushl	%ebp
000029c1	movl	%esp,%ebp
000029c3	pushl	%ebx
000029c4	subl	$0x14,%esp
000029c7	movl	0x08(%ebp),%ebx
000029ca	movl	$__ZTV21VoodooWirelessCommand,(%ebx)
000029d0	movl	%ebx,(%esp)
000029d3	calll	__ZN9IOCommandD2Ev
000029d8	movl	%ebx,%eax
000029da	addl	$0x14,%esp
000029dd	popl	%ebx
000029de	leave
000029df	ret
__ZN21VoodooWirelessCommandD0Ev:
000029e0	pushl	%ebp
000029e1	movl	%esp,%ebp
000029e3	pushl	%ebx
000029e4	subl	$0x14,%esp
000029e7	movl	0x08(%ebp),%ebx
000029ea	movl	$__ZTV21VoodooWirelessCommand,(%ebx)
000029f0	movl	%ebx,(%esp)
000029f3	calll	__ZN9IOCommandD2Ev
000029f8	movl	%ebx,(%esp)
000029fb	movl	$0x00000020,0x04(%esp)
00002a03	calll	__ZN8OSObjectdlEPvm
00002a08	movl	%ebx,%eax
00002a0a	addl	$0x14,%esp
00002a0d	popl	%ebx
00002a0e	leave
00002a0f	ret
__ZNK21VoodooWirelessCommand12getMetaClassEv:
00002a10	pushl	%ebp
00002a11	movl	$__ZN21VoodooWirelessCommand10gMetaClassE,%eax
00002a16	movl	%esp,%ebp
00002a18	leave
00002a19	ret
__ZN21VoodooWirelessCommand9MetaClassC1Ev:
00002a1a	pushl	%ebp
00002a1b	movl	%esp,%ebp
00002a1d	pushl	%ebx
00002a1e	subl	$0x14,%esp
00002a21	movl	0x08(%ebp),%ebx
00002a24	movl	__ZN21VoodooWirelessCommand10superClassE,%eax
00002a29	movl	$0x00000020,0x0c(%esp)
00002a31	movl	$0x0000399c,0x04(%esp)
00002a39	movl	%ebx,(%esp)
00002a3c	movl	%eax,0x08(%esp)
00002a40	calll	__ZN11OSMetaClassC2EPKcPKS_j
00002a45	movl	%ebx,%eax
00002a47	movl	$__ZTVN21VoodooWirelessCommand9MetaClassE,(%ebx)
00002a4d	addl	$0x14,%esp
00002a50	popl	%ebx
00002a51	leave
00002a52	ret
00002a53	nop
__ZN21VoodooWirelessCommand9MetaClassC2Ev:
00002a54	pushl	%ebp
00002a55	movl	%esp,%ebp
00002a57	pushl	%ebx
00002a58	subl	$0x14,%esp
00002a5b	movl	0x08(%ebp),%ebx
00002a5e	movl	__ZN21VoodooWirelessCommand10superClassE,%eax
00002a63	movl	$0x00000020,0x0c(%esp)
00002a6b	movl	$0x0000399c,0x04(%esp)
00002a73	movl	%ebx,(%esp)
00002a76	movl	%eax,0x08(%esp)
00002a7a	calll	__ZN11OSMetaClassC2EPKcPKS_j
00002a7f	movl	%ebx,%eax
00002a81	movl	$__ZTVN21VoodooWirelessCommand9MetaClassE,(%ebx)
00002a87	addl	$0x14,%esp
00002a8a	popl	%ebx
00002a8b	leave
00002a8c	ret
00002a8d	nop
__ZN21VoodooWirelessCommandC1Ev:
00002a8e	pushl	%ebp
00002a8f	movl	%esp,%ebp
00002a91	pushl	%ebx
00002a92	subl	$0x14,%esp
00002a95	movl	0x08(%ebp),%ebx
00002a98	movl	$__ZN21VoodooWirelessCommand10gMetaClassE,0x04(%esp)
00002aa0	movl	%ebx,(%esp)
00002aa3	calll	__ZN9IOCommandC2EPK11OSMetaClass
00002aa8	movl	$__ZTV21VoodooWirelessCommand,(%ebx)
00002aae	movl	$__ZN21VoodooWirelessCommand10gMetaClassE,(%esp)
00002ab5	calll	__ZNK11OSMetaClass19instanceConstructedEv
00002aba	movl	%ebx,%eax
00002abc	addl	$0x14,%esp
00002abf	popl	%ebx
00002ac0	leave
00002ac1	ret
__ZNK21VoodooWirelessCommand9MetaClass5allocEv:
00002ac2	pushl	%ebp
00002ac3	movl	%esp,%ebp
00002ac5	pushl	%ebx
00002ac6	subl	$0x14,%esp
00002ac9	movl	$0x00000020,(%esp)
00002ad0	calll	__ZN8OSObjectnwEm
00002ad5	movl	%eax,%ebx
00002ad7	xorl	%eax,%eax
00002ad9	testl	%ebx,%ebx
00002adb	je	0x00002ae7
00002add	movl	%ebx,(%esp)
00002ae0	calll	__ZN21VoodooWirelessCommandC1Ev
00002ae5	movl	%ebx,%eax
00002ae7	addl	$0x14,%esp
00002aea	popl	%ebx
00002aeb	leave
00002aec	ret
00002aed	nop
__ZN21VoodooWirelessCommandC2Ev:
00002aee	pushl	%ebp
00002aef	movl	%esp,%ebp
00002af1	pushl	%ebx
00002af2	subl	$0x14,%esp
00002af5	movl	0x08(%ebp),%ebx
00002af8	movl	$__ZN21VoodooWirelessCommand10gMetaClassE,0x04(%esp)
00002b00	movl	%ebx,(%esp)
00002b03	calll	__ZN9IOCommandC2EPK11OSMetaClass
00002b08	movl	$__ZTV21VoodooWirelessCommand,(%ebx)
00002b0e	movl	$__ZN21VoodooWirelessCommand10gMetaClassE,(%esp)
00002b15	calll	__ZNK11OSMetaClass19instanceConstructedEv
00002b1a	movl	%ebx,%eax
00002b1c	addl	$0x14,%esp
00002b1f	popl	%ebx
00002b20	leave
00002b21	ret
__ZN21VoodooWirelessCommand8withTypeENS_11CommandTypeEPvS1_:
00002b22	pushl	%ebp
00002b23	movl	%esp,%ebp
00002b25	pushl	%ebx
00002b26	subl	$0x14,%esp
00002b29	movl	$0x00000020,(%esp)
00002b30	calll	__ZN8OSObjectnwEm
00002b35	testl	%eax,%eax
00002b37	movl	%eax,%ebx
00002b39	je	0x00002b55
00002b3b	movl	%eax,(%esp)
00002b3e	calll	__ZN21VoodooWirelessCommandC1Ev
00002b43	movl	0x08(%ebp),%eax
00002b46	movl	%eax,0x14(%ebx)
00002b49	movl	0x0c(%ebp),%eax
00002b4c	movl	%eax,0x18(%ebx)
00002b4f	movl	0x10(%ebp),%eax
00002b52	movl	%eax,0x1c(%ebx)
00002b55	movl	%ebx,%eax
00002b57	addl	$0x14,%esp
00002b5a	popl	%ebx
00002b5b	leave
00002b5c	ret
00002b5d	nop
__Z41__static_initialization_and_destruction_0ii:
00002b5e	pushl	%ebp
00002b5f	movl	%esp,%ebp
00002b61	subl	$0x18,%esp
00002b64	cmpl	$0x0000ffff,%edx
00002b6a	movl	%ebx,0xf8(%ebp)
00002b6d	sete	%bl
00002b70	cmpl	$0x01,%eax
00002b73	movl	%esi,0xfc(%ebp)
00002b76	movl	%eax,%esi
00002b78	sete	%al
00002b7b	testb	%al,%bl
00002b7d	je	0x00002b8b
00002b7f	movl	$__ZN21VoodooWirelessCommand10gMetaClassE,(%esp)
00002b86	calll	__ZN21VoodooWirelessCommand9MetaClassC1Ev
00002b8b	testl	%esi,%esi
00002b8d	sete	%al
00002b90	testb	%al,%bl
00002b92	je	0x00002ba1
00002b94	movl	$__ZN21VoodooWirelessCommand10gMetaClassE,(%esp)
00002b9b	call	*__ZTVN21VoodooWirelessCommand9MetaClassE+0x00000008
00002ba1	movl	0xf8(%ebp),%ebx
00002ba4	movl	0xfc(%ebp),%esi
00002ba7	leave
00002ba8	ret
00002ba9	nop
__ZN21VoodooWirelessCommand9MetaClassD0Ev:
00002baa	pushl	%ebp
00002bab	movl	%esp,%ebp
00002bad	pushl	%ebx
00002bae	subl	$0x14,%esp
00002bb1	movl	0x08(%ebp),%ebx
00002bb4	movl	$__ZTVN21VoodooWirelessCommand9MetaClassE,(%ebx)
00002bba	movl	%ebx,(%esp)
00002bbd	calll	__ZN11OSMetaClassD2Ev
00002bc2	movl	%ebx,%eax
00002bc4	addl	$0x14,%esp
00002bc7	popl	%ebx
00002bc8	leave
00002bc9	ret
__GLOBAL__I__ZN21VoodooWirelessCommand10gMetaClassE:
00002bca	pushl	%ebp
00002bcb	movl	$0x0000ffff,%edx
00002bd0	movl	%esp,%ebp
00002bd2	movl	$0x00000001,%eax
00002bd7	leave
00002bd8	jmpl	__Z41__static_initialization_and_destruction_0ii
00002bdd	nop
__GLOBAL__D__ZN21VoodooWirelessCommand10gMetaClassE:
00002bde	pushl	%ebp
00002bdf	movl	$0x0000ffff,%edx
00002be4	movl	%esp,%ebp
00002be6	xorl	%eax,%eax
00002be8	leave
00002be9	jmpl	__Z41__static_initialization_and_destruction_0ii
__ZN21VoodooWirelessCommand9MetaClassD1Ev:
00002bee	pushl	%ebp
00002bef	movl	%esp,%ebp
00002bf1	pushl	%ebx
00002bf2	subl	$0x14,%esp
00002bf5	movl	0x08(%ebp),%ebx
00002bf8	movl	$__ZTVN21VoodooWirelessCommand9MetaClassE,(%ebx)
00002bfe	movl	%ebx,(%esp)
00002c01	calll	__ZN11OSMetaClassD2Ev
00002c06	movl	%ebx,%eax
00002c08	addl	$0x14,%esp
00002c0b	popl	%ebx
00002c0c	leave
00002c0d	ret
__start:
00002c0e	pushl	%ebp
00002c0f	movl	%esp,%ebp
00002c11	subl	$0x18,%esp
00002c14	movl	%ebx,0xf8(%ebp)
00002c17	movl	0x0c(%ebp),%ebx
00002c1a	movl	%esi,0xfc(%ebp)
00002c1d	movl	0x08(%ebp),%esi
00002c20	movl	%ebx,0x04(%esp)
00002c24	movl	%esi,(%esp)
00002c27	calll	_OSRuntimeInitializeCPP
00002c2c	testl	%eax,%eax
00002c2e	jne	0x00002c49
00002c30	movl	__realmain,%ecx
00002c36	testl	%ecx,%ecx
00002c38	je	0x00002c49
00002c3a	movl	%ebx,0x0c(%ebp)
00002c3d	movl	0xf8(%ebp),%ebx
00002c40	movl	%esi,0x08(%ebp)
00002c43	movl	0xfc(%ebp),%esi
00002c46	leave
00002c47	jmp	*%ecx
00002c49	movl	0xf8(%ebp),%ebx
00002c4c	movl	0xfc(%ebp),%esi
00002c4f	leave
00002c50	ret
__stop:
00002c51	pushl	%ebp
00002c52	movl	%esp,%ebp
00002c54	subl	$0x18,%esp
00002c57	movl	%ebx,0xf8(%ebp)
00002c5a	movl	0x0c(%ebp),%ebx
00002c5d	movl	%esi,0xfc(%ebp)
00002c60	movl	0x08(%ebp),%esi
00002c63	movl	%ebx,0x04(%esp)
00002c67	movl	%esi,(%esp)
00002c6a	calll	_OSRuntimeFinalizeCPP
00002c6f	testl	%eax,%eax
00002c71	jne	0x00002c8c
00002c73	movl	__antimain,%ecx
00002c79	testl	%ecx,%ecx
00002c7b	je	0x00002c8c
00002c7d	movl	%ebx,0x0c(%ebp)
00002c80	movl	0xf8(%ebp),%ebx
00002c83	movl	%esi,0x08(%ebp)
00002c86	movl	0xfc(%ebp),%esi
00002c89	leave
00002c8a	jmp	*%ecx
00002c8c	movl	0xf8(%ebp),%ebx
00002c8f	movl	0xfc(%ebp),%esi
00002c92	leave
00002c93	ret
