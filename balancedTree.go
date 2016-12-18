/**
 * Problem from leetcode.com
 *
 * Balanced Binary Tree
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more than 1.
 *
 */


/**
 * Definition for a binary tree node.
*/
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

/**
 * Return the maximum depth of a given node taken as root
 */
func depth( root *TreeNode ) float64 {

    if( root.Left != nil ) {

        // When both children exist, return the largest depth + 1
        if( root.Right != nil ) { return math.Max(depth(root.Left), depth(root.Right)) + 1 }

        // When only the left child exists, return left child's + 1
        return depth( root.Left ) + 1
    }

    // When only the right child exists, return right child's + 1
    if( root.Right != nil ) { return depth( root.Right ) + 1 }

    // Return 0 for there's no extra length when there are no children
    return 0
}

func isBalanced(root *TreeNode) bool {

    // Fail fast: an empty tree is balanced
    if( root == nil ) { return true }

    // A tree is balanced if both left and right subtrees are balanced and are equally deep with an error of 1 unit
    if( root.Left != nil ) {
        if( root.Right != nil ) {
            return isBalanced( root.Left ) && isBalanced( root.Right ) && math.Abs(depth(root.Left) - depth(root.Right)) <= 1
        }
        return depth( root ) <= 1
    }

    if( root.Right != nil )    { return depth( root ) <= 1 }

    // A tree with only one node is balanced
    return true
}
