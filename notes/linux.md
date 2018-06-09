LINUX
=====

Definitions
----------

**Process**: executing instance of a program.
**Kernel**: is a program that constitutes the central core of a computer operating
system. It is not a process, but rather a controller of processes, and it has
complete control over everything that occurs on the system. This includes
managing individual user process within user space and preventing them from 
interfering with each other.

User space/userland
------------------

* Portion of system memory in which user processes run.
* Refers to all of the code in an operating system that lives outside of the 
kernel.
* Programs living in user space request data for the Kernel making system call.
This data can live in register, external drivers, memory or disk. Example:
    - allocating memory (variables)
    - opening a file.
Memory and files often store sensitive information owned by different users, 
so access must be requested from the kernel through system call.

Kernel space
------------

* Portion of memory in which the Kernel executes and provides its services
* Kernel space can be accessed by user processes only through the user of *system
calls*. System calls are requests in a Unix-like operating system by an active process
for a service performed by the kernel, such as input/output (I/O) or process
creation. Ac active process is a process that is currently progressing in the CPU,
as contrasted with a process that is waiting for its next turn in the CPU. I/O
is any program, operation or device that transfers data to or from a CPU and to
or from a peripheral device (such as disks, keyboards, mice and printers)

Interaction
----------

A typical program gets access to resources in the kernel through layers of 
abstraction. Typically the system call are called through libraries such as
glibc, or through an interpreter such as Ruby, Python or the Java Virtual 
Machine (JVM)

References
----------

- `man 2 syscalls`
- (Architecting Containers Part 1: Why Understanding User Space vs. Kernel Space Matters)[https://rhelblog.redhat.com/2015/07/29/architecting-containers-part-1-user-space-vs-kernel-space/]
- (Architecting Containers Part 2: Why the User Space Matters)[https://rhelblog.redhat.com/2015/09/17/architecting-containers-part-2-why-the-user-space-matters-2/]
- (Architecting Containers Part 3: How the User Space Affects Your Application)[https://rhelblog.redhat.com/2015/11/10/architecting-containers-part-3-how-the-user-space-affects-your-application/]
- (User space definition)[http://www.linfo.org/user_space.html]
- (Kernel space definition)[http://www.linfo.org/kernel_space.html]

