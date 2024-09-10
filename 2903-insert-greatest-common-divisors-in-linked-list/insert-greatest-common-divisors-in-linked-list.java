/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private int f(int a,int b){
        while(b!=0){
            if(a>b)a=a-b;
            else b=b-a;
        }
        return a;
    }
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if(head==null || head.next==null)return head;
        ListNode dummy =new ListNode();
        ListNode curr =dummy;

        curr.next =head;
        curr =curr.next;

        head=head.next;

        while(head!=null){
            int gcd =f(curr.val,head.val);
            ListNode _gcd =new ListNode(gcd);
            
            curr.next =_gcd;
            curr=curr.next;

            curr.next=head;
            curr=curr.next;

            head=head.next;
        }
        return dummy.next;
    }
}