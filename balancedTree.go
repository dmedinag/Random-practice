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
 * Naive approach: Top down approach, traversing the tree BFS, O(N^2)
 */
func depthBFS( root *TreeNode ) float64 {
    // Fail fast: a tree with no nodes has no length
    if( root == nil ) { return 0 }

    return math.Max( depth(root.Left), depth(root.Right) ) + 1
}

func isBalancedNaive(root *TreeNode) bool {

    // Fail fast: an empty tree is balanced
    if( root == nil ) { return true }
    // A tree is balanced if both left and right subtrees are balanced and are equally deep with an error of 1 unit
    return isBalanced( root.Left ) && isBalanced( root.Right ) && math.Abs(depth(root.Left) - depth(root.Right)) <= 1
}

/**
 * Smart approach: Bottom up approach, traversing the tree DFS, O(N)
 */
func depthDFS( root *TreeNode ) float64 {

    if( root == nil ) { return 0; }

    left := depth( root.Left )
    if( left == -1 ) { return -1 }
    right := depth( root.Right )
    if( right == -1 ) { return -1 }

    if ( math.Abs( left - right ) > 1 ) { return -1 }
    return math.Max(left, right) + 1
}

func isBalancedSmart(root *TreeNode) bool { return depth( root ) != -1 }
