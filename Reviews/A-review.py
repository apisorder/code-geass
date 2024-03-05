
#add-two-number
    #C++
        #source
            #Linked List -> struct + : initialized list {}
            #*ListNode *dummyHead = new ListNode();
            #if return dummyHead.next, delete dummyHead (memory leak)
        #driver
            #Solution solution;
            #LinkedList l1 = ListNode(x, new ListNode(y, new ListNode(z)))

    #Java
        #source
            #linked list -> no defaults needed
            #make function public
            #ListNode dummyHead = new ListNode();
        #driver
            #Solution solution = new Solution();       

    #Python
        #source
            #linked list -> __init__(self, val=0, next=None)
        #driver
            #solution = Solution()

#add-two-number-2
    #C++
        #source
            #reverse->remember to return reverseList(dummyHead.next)
            #stack->#include <stack> && std::stack<int>
            #stack->sum = dummyHead.val && dummyHead.val = sum
            #stack->if return dummyHead.next, delete dummyHead (memory leak)
            #length->sum = current.val + carry;
            #length->ListNode *head = new ListNode(sum, dummyHead);
        #driver
            #Solution solution;

    #Java
        #source
            #reverse->remember to return reverseList(dummyHead.next)
            #stack->import java.util.Stack && Stack<Integer> stack = new Stack<Integer>()
            #stack->sum = dummyHead.val && dummyHead.val = sum
            #length->sum = current.val + carry;
            #length->ListNode head = new ListNode(sum, dummyHead);
        #driver
            #Solution solution = new Solution();

    #Python
        #source
            #reverse->remember to return reverseList(dummyHead.next)
            #stack->sum = dummyHead.val && dummyHead.val = sum
            #length->sum1 = carry + current.val 
            #length->head = ListNode( sum1, dummyHead )
        #driver
            #solution = Solution()