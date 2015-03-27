No longer maintained. An exported copy exists on [GitHub](https://github.com/hyqneuron/asfermi)

<b><font size='5'>asfermi: An assembler for the NVIDIA Fermi Instruction Set</font></b>

asfermi is an assembler for the NVIDIA Fermi ISA. It can output assembled kernels directly into cubin files (an ELF format file that NVIDIA uses to store its machine code), or it can be used to modify existing cubin kernels. Currently around 70 instructions are supported. asfermi works on both 32-bit and 64-bit platforms.

Fermi is [NVIDIA](http://en.wikipedia.org/wiki/Nvidia)'s current-generation Graphics Processing Unit (GPU) architecture (as of 2011). NVIDIA does not disclose much of the detail of its current architecture. While NVIDIA provides an assembly-like language, [PTX](http://en.wikipedia.org/wiki/Parallel_Thread_Execution), for the use in [CUDA](http://en.wikipedia.org/wiki/CUDA), PTX is actually treated as a high-level language that is compiled and optimized with ptxas. As a result, direct access to the hardware using real opcodes is not available. With this assembler, real opcodes can be directly generated on a one-to-one basis from instruction. Aided with this direct means of interaction, hopefully all the important details of the GF1xx architecture may be uncovered, so that the knowledge may be used for more accurate optimization on the Fermi (and later generations of) GPUs.

**Keywords**: CUDA, [Fermi](http://en.wikipedia.org/wiki/GeForce_400_Series), Assembler

**Documentation**: For a list of the wiki pages and their brief descriptions, see [Index](IndexPage.md).

**Recent Edit**
  * Some interesting discussion has taken place in the [asfermi Google Group](http://groups.google.com/group/asfermi). You can browse through the discussions to find out more.
  * [Updates](Updates.md): Last updated: **13th Jan**: mmarc`__` contributed a patch to make asfermi callable as a library
  * [Plan](Plan.md): Updated to-dos.
  * [FAQ](FAQ.md): FAQ for coding
  * [KnownIssues](KnownIssues.md)
  * [S2R\_Test](S2R_Test.md): contains some preliminary result of the instruction scheduling pattern
  * [LEPC\_Test](LEPC_Test.md)
  * [CodeExample](CodeExample.md): code samples


---

## Current Development State ##
All must-have instructions are now supported.
A branch [libasfermi](http://code.google.com/p/asfermi/source/browse/#svn%2Fbranches%2Flibasfermi) has been added.

For more information regarding the state of asfermi, see [Updates](Updates.md).


---

## Other information: ##
Fermi's instruction set is half-disclosed through the disassembler, cuobjdump, provided by NVIDIA in CUDA toolkit 4.0. Instruction names are roughly included in the cuobjdump.pdf of the toolkit's documentation.


A disassembler(decuda) and an assembler(cudasm) for the G80 ISA can be found [here](https://github.com/laanwj/decuda/wiki).

A paper that reveals the details of the GT200 architecture: [Demystifying GPU architecture through Microbenchmarking](http://www.stuffedcow.net/files/gpuarch-ispass2010.pdf)