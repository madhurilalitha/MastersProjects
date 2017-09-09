Project 1-1: Fibonacci Series Design Document

We have processed this program in Linux Environment in C programming using pthreads.
The output is verified and found it working as expected.
The threading logic used in the design, creates multiple threads where the sum is calculated at each individual level of the thread.
The core Fibonacci logic remains same where the current number is moved to a temporary variable and the previous sum is added to the
current number and sum is made as the current number.
This core logic is called every time using threading techniques thus processing the thread processes parallely.


Project 1-2: Statistical Functions program Report.

Design: •	We used pthread techniques to obtain the logic for finding the maximum, minimum and average of the given input of numbers. 
•	Three different mutually exclusive threads are defined to handle three different logic. •	In order to obtain synchronization for the 
three functions, we used sleep functions which provides a bit of delay for different threads thus achieving sooth processing. 
•	In the main method, the three different threads are created using pthread_create with corresponding thread ids (tid in this case).
•	The given number is compared in the minimum value thread and if it is found less, the loop repeats until the minimum value is found.
•	Similar logic is applied for the maximum value.
•In case of finding the average, for every input is added to the original sum and the mean is taken at the end and the average is displayed
