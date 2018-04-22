Integer V lies strictly between integers U and W if U < V < W or if U > V > W.

A non - empty zero - indexed array A consisting of N integers is given.
A pair of indices(P, Q), where 0 P < Q c N, is said to have adjacent values
if no value in the array lies strictly between values A[P] and A[Q],
and in addition A[P] * A[Q].

For example, in array A such that :
A[0] = 0
A[1] = 3
A[2] = 3
A[3] = 7
A[4] = 5
A[5] = 3
A[6] = 11
A[7] = 1

the following pairs of indices have adjacent values :
(0, 7), (1, 4), (1, 7),
(2, 4), (2, 7), (3, 4),
(3, 5), (4, 5), (5, 7)

For example, indices 4 and 5 have adjacent values because the values
A[4] = 5 and A(5] = 3 are different, and there is no value in array A that
lies strictly between them - the only such value could be the number 4,
which is not present in the array.

Given two indices P and Q, their distance is defined as abs(P - Q),
where abs(X) = X for X 0, and abs(X) = -X for X < 0.
For example, the distance between indices 4 and 5 is 1 because
abs(4 - 5) = (5 - 4) = 1.

Write a function :

class Solution {
    public int solution(int[] A);
}

that, given a non - empty zero - indexed array A consisting of N integers,
returns the minimum distance between indices of this array that have adjacent values.
The function should return -1 if no adjacent indices exist.

For example, given array A such that :
A[0] = 1 A[1] = 4
A[2] = 7 A[3] = 3
A[4] = 3 A[5] = 5

the function should return 2 because :
• indices 1 and 3 are adjacent because A[1] != A(3] and the array does not
contain any value that lies strictly between A[1] = 4 and A[3] = 3;
• the distance between these indices is abs(1 - 3) = 2;
• no other pair of adjacent indices that has a smaller distance exists.

Assume that :
• N is an integer within the range[1..40, 000];
• each element of array A is an integer withinthe range
[-2, 147, 483, 648..2, 147, 483, 647].

Complexity:
• expected worst - case time complexity is 0(N*log(N));
• expected worst - case space complexity is 0(N),
beyond input storage(not counting the storage required for input arguments).
