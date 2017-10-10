/************************************************************
  * Ackermann Function
    A(m, n) =
      n + 1             when m = 0
      A(m-1, 1)         when m != 0, n = 0
      A(m-1, A(m, n-1)) when m != 0, n != 0

  ********** Alogrithm with recursions **********

  ** Function
    ```
    int Ackerman(int m, int n);
    ```
    The most primitive algorithm.

  ** Function
    ```
    int Ackerman_opt(int m, int n);
    ```
    I did some calculations and got some expressions which are closer to the answer.

        when m = 1, n >= 1
            A(1, n) = A(0, A(1, n-1)) = A(1, n-1) + 1
         => A(1, n) = A(1, n-1) + 1 = A(1, n-2) + 2 = ... = A(1, 1) + n-1
                    = n+2

        when m = 2, n >= 1
            A(2, n) = A(1, A(2, n-1)) = A(2, n-1) + 2
         => A(2, n) = A(2, n-1) + 2 = A(2, n-2) + 4 = ... = A(2, 1) + 2(n-1)
                    = 2n+3

        when m = 3, n >= 1
            A(3, n) = A(2, A(3, n-1)) = 2*A(3, n-1) + 3
         => A(3, n) = 2*A(3, n-1) + 3
         => A(3, n) + 3 = 2*[A(3, n-1) + 3]
         => A(3, n) = [A(3, 1) + 3]*2^(n-1) - 3
                    = 2^(n+3) - 3

    But for m == 4, I can only get following recursive relationship.
        when m = 4, n >= 1
            A(4, n) = A(3, A(4, n-1)) = 2^[A(4, n-1) + 3] - 3

    With the growth of m, the expression becomes much more complicated. I believe that the growth rate of the function makes it meaningless to do more calculations.
    In spite of this, I still did a little optimization for m > 4. On the base of the primitive function, I found that
        when m > 1, n = 0
            A(m, 0) = A(m-1, 1) (m-1 > 0)
                    = A(m-2, A(m-1, 0))
    This may reduce the number of recursions with little success.

  ********** Alogrithm without recursions **********

  ** Struct
    ```
    struct arg { int m, n; };
    ```
    Define a structure with m and n which acts as elemType of the stack. In this way, I avoid operating two stacks with the same operation at the same time.

  ** Function
    ```
    int Ackerman_stack(int m, int n);
    ```
    Initilize - Get m and n.
                Push them into the stack.
    Loop      - Access next element.
                If A(m. n) can be found in data or it can be calculated during the loop, remove it from the stack.
                Or A(m, n) can must be expressed with some A(a, b).
                    If it can be found in data, return it.
                    Or push {a, b} into the stack.
    Return    - When the Loop is finished, A(m, n) can be found by data[m][n]

************************************************************/
