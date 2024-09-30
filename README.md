dsa1: 
AIM-Given an array 'a' of n integers. Generate an array 'b' of same size such that b[i] contains product of all elements of array 'a' except for the number at same index in the array (i.e a[i]) and print array 'b'.
working- Input the array a.
Initialize array b.
Calculate products from the left.
For each element a[i], maintain a cumulative product of all elements to the left of i.
Calculate products from the right.
Similarly, maintain a cumulative product from the right and multiply it with the left product calculated earlier.
OUTPUT
120 60 40 30 24

dsa2:
AIM -A ball is dropped with a certain velocity from a certain height. Its velocity decreases by half after each bounce. Find the number of bounces(hits) it takes before coming to rest.
working- Input: The user provides the initial velocity.
Threshold: We assume the ball comes to rest when its velocity is less than 0.01 (this can be adjusted).
Loop: In each iteration, the velocity is halved, and the bounce count is increased.
End Condition: The loop stops when the velocity drops below the threshold, and the program outputs the number of bounces.
OUTPUT
Enter the initial velocity of the ball: 10
Bounce 0: Velocity = 10
Bounce 1: Velocity = 5
Bounce 2: Velocity = 2.5
Bounce 3: Velocity = 1.25
Bounce 4: Velocity = 0.625
Bounce 5: Velocity = 0.3125
Bounce 6: Velocity = 0.15625
Bounce 7: Velocity = 0.078125
Bounce 8: Velocity = 0.0390625
Bounce 9: Velocity = 0.01953125
Bounce 10: Velocity = 0.00976562
The ball comes to rest after 11 bounces.

dsa.3 :
AIM- Find all unique triplets (x,y,z) in the list such that the sum of any two numbers in the triplet equals the third number. The output should print these triplets 
working- Sorting: Sorting the input list helps in simplifying the search process for combinations and ensures that the triplets are added in a consistent order.

Nested loops: The three loops (i, j, and k) iterate through all combinations of the list elements, generating all possible triplets.

Condition checking: For each triplet 
(
𝑥
,
𝑦
,
𝑧
)
(x,y,z), we check if the sum of any two numbers equals the third.

Using a set: To avoid duplicate triplets, we use a set which only stores unique elements. Triplets are stored as tuples.

Output: The final step is to output all the unique triplets that satisfy the given condition.
(1, 2, 3)
(2, 4, 6)
(1, 3, 4)

dsa.5 : 
AIM- Given a list of n consecutive integers starting from a given number with one integer is missing from this list due to an error. Find and print the missing integer. .
working-Input:
The vector arr holds the sequence with one missing integer.
The variable n represents the total number of integers that should be in the sequence.
The variable start is the starting number of the sequence.
findMissingInteger function:
First, it calculates the total sum of n consecutive integers using the formula mentioned earlier.
Then, it calculates the sum of the numbers present in the list.
Finally, it returns the difference between the two sums, which is the missing integer.
Output: The output for the provided input will be:
The missing number is: 7

dsa.6: 
AIM-Given a length n, generate all possible pairs of 'T' and 'F' Strings.
working-Start with an empty string.
For each position, append 'T' and recursively fill the remaining positions.
Similarly, append 'F' and recursively fill the remaining positions.
Once a string of length n is created, output it.
OUTPUT:
TTT
TTF
TFT
TFF
FTT
FTF
FFT
FFF

dsa 7 :
AIM- Find the sum of elements of a given list recursively
working-
Input List: {1, 2, 3, 4, 5}
Function is called as recursiveSum(arr, 5).
First Call (n = 5):
arr[4] = 5 is added to recursiveSum(arr, 4).
Second Call (n = 4):
arr[3] = 4 is added to recursiveSum(arr, 3).
Third Call (n = 3):
arr[2] = 3 is added to recursiveSum(arr, 2).
Fourth Call (n = 2):
arr[1] = 2 is added to recursiveSum(arr, 1).
Fifth Call (n = 1):
arr[0] = 1 is added to recursiveSum(arr, 0).
Base Case (n = 0):
The function returns 0.
OUTPUT:
Sum of elements in the list: 15

dsa8:
AIM-Write a program to insert an element at desired position:
working-Input array size and elements: The user inputs the number of elements in the array, and these elements are stored in an array.
Input element and position: The user enters the element to be inserted and the desired position (1-based index).
Shift elements: All elements starting from the given position are shifted one place to the right to create space for the new element.
Insert the element: The new element is placed at the desired position.
Display result: The array is printed after insertion.
OUTPUT:
Enter the size of the array: 5
Enter 5 elements: 1 2 3 4 5
Enter the element to insert: 99
Enter the position to insert the element (1-based index): 3
Array after insertion: 1 2 99 3 4 5

dsa9: 
AIM Write a program to  delete the element from end in array.Initialize the array:
working-An array arr[] with 5 elements is created.
The size of the array is determined using sizeof(arr) / sizeof(arr[0]).
Display the array:
The function displayArray is used to print the current elements in the array.
Delete the last element:
Decreasing the size by 1 effectively removes the last element from the array.
The actual memory isn't freed, but the last element is no longer considered part of the array in logical terms.
Display the updated array:
The updated array is displayed after removing the last element.
OUTPUT:
Initial array: 10 20 30 40 50 
Array after deleting the last element: 10 20 30 40 

dsa10: 
AIM- Write a program to  delete the element from any index in array
working-: The array arr is initialized with a size of 5, containing elements {10, 20, 30, 40, 50}.
The program displays the array before any changes.
The user is prompted to enter an index from which an element should be deleted.
The deleteElement function shifts elements leftwards, starting from the given index, and reduces the array's size.
The array is displayed after deletion.
OUTPUT:
Initial array: 10 20 30 40 50 
Enter index to delete element: 2
Array after deletion: 10 20 40 50

Singly linked list. 
AIM-Design a singly linked list using struct and perform search, update, insert, sort and delete opeartions on it based on user specifications.
OUTPUT:
1. Insert
2. Delete
3. Search
4. Update
5. Display
6. Exit
Enter your choice: 1
Enter value to insert: 10
Inserted 10 into the list.

1. Insert
2. Delete
3. Search
4. Update
5. Display
6. Exit
Enter your choice: 1
Enter value to insert: 20
Inserted 20 into the list.

1. Insert
2. Delete
3. Search
4. Update
5. Display
6. Exit
Enter your choice: 5
Linked List: 10 -> 20 -> NULL

Doubly linked list
AIM : Design a doubly linked list using class and perform search, update, insert and delete opearations on it based on user specifications.
OUTPUT:
Doubly Linked List: 10 20 30 40 
20 found in the list!
Value updated from 20 to 25
Doubly Linked List after update: 10 25 30 40 
Node with value 30 deleted!
Doubly Linked List after deletion: 10 25 40 

Circular linked list
AIM : Design a circular linked list using class and perform search, update, insert and delete opearations on it based on user specifications.

OUTPUT:
Original List: 170 45 75 90 802 24 2 66 
Sorted List: 2 24 45 66 75 90 170 802 




Horner rule
AIM-Calculate the value of function given by f(x)=a0 + a1(x) + a2(x^2)....+an(x^n), where a is the array and x and n are integers using Horner's Rule.
working:horner Function: Implements Horner's Rule to evaluate the polynomial. It starts from the highest degree term and progressively reduces the power of 
𝑥
x, updating the result at each step.
Input:
n: Degree of the polynomial.
coeffs[]: Array of coefficients where coeffs[i] is the coefficient 
𝑎
𝑖
a 
i
​x: The value of 
𝑥
x at which to evaluate the polynomial.
Result Calculation: Horner's Rule reduces the complexity of the polynomial evaluation.
OUTPUT:
Enter the degree of the polynomial (n): 2
Enter the coefficients (a0, a1, ..., an):
Coefficient a0: 2
Coefficient a1: 3
Coefficient a2: 5
Enter the value of x: 2
The value of the polynomial at x = 2 is: 24


dsa.11
AIM- Write a program that measures the time taken to perform a Linear Search on arrays of increasing sizes.
working:
Generates arrays of different sizes.
Performs a linear search for a target element (usually the last element for the worst case).
Measures the time taken for each search using the <chrono> library.
OUTPUT:
Array Size: 10000, Time taken: 0.012 ms
Array Size: 20000, Time taken: 0.024 ms
Array Size: 30000, Time taken: 0.036 ms
Array Size: 40000, Time taken: 0.048 ms
Array Size: 50000, Time taken: 0.060 ms









