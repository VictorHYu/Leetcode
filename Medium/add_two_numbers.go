/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	node := new(ListNode)
	current := node

	carry := 0

	for {
		sum := l1.Val + l2.Val
		digit := (sum + carry) % 10
		current.Val = digit
		carry = (sum + carry) / 10

		if l1.Next != nil && l2.Next != nil {
			l1 = l1.Next
			l2 = l2.Next
		} else if l2.Next != nil {
			l1.Val = 0
			l2 = l2.Next
		} else if l1.Next != nil {
			l2.Val = 0
			l1 = l1.Next
		} else {
			break
		}

		current.Next = new(ListNode)
		current = current.Next
	}

	// Overflow - add last digit
	if carry != 0 {
		current.Next = new(ListNode)
		current = current.Next
		current.Val = carry
	}

	return node
}
