#   in JavaScript
# let swap = (a, b) =>
# {
#   [a, b] = [b, a];
#     return [a, b];
# }
#   let result = swap[a, b];
#   a = result[0]; b = result[1];

#   in Python
#   not new keyword used
#   def swap(a, b):
#       return b, a
#   a, b, = swap(a, b)

#   in Java
#   int swap(int a, int b)
#   {
#       return a;
#   }
#   b = swap(a, a=b);

#   in C++
#   void swap(int *a, int *b)
#   {
#       *a = *a ^ *b;
#       *b = *a ^ *b;
#       *a = *a ^ *b;
#   }
#   swap(&a, &b);