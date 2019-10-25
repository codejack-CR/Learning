package ds;
import java.util.Arrays;
import java.util.Stack;

public class Tour {
    Node root = new Node();
    Node[] members;
    //Private method to create a tree from the given Node array
    private Node makeTree(Node[] p) {
	if(p.length==1)return p[0];
	int newSize = (p.length%2==0)?p.length/2:p.length/2+1;
	Node[] win = new Node[newSize];
	for(int i=0;i<newSize;i++) {
	    win[i] = new Node();
	}
	if(p.length%2!=0) {
		 win[newSize-1].setVal(p[p.length-1].val);
		 win[newSize-1].setRight(p[p.length-1].right);
		 win[newSize-1].setLeft(p[p.length-1].left);
	}
	for(int i=0,index=0;i<p.length-(p.length%2);i+=2,index++) {
	    if(p[i].val > p[i+1].val) {
		win[index].setVal(p[i].val);
	    }
	    else {
		win[index].setVal(p[i+1].val);
	    }
	    win[index].setRight(p[i+1]);
	    win[index].setLeft(p[i]);
	}
	return makeTree(win);
    }
    //Insertion in the Tournament tree by recreating the tree
    public void insert(int e) {
	Node[] newArr = new Node[this.members.length+1];
	int index=0;
	for(Node n: this.members) {
	    newArr[index++] = n;
	}
	Node newNode = new Node(e);
	newArr[this.members.length] = newNode;
	this.members = newArr;
	//Create a new tournament tree
	int[] newmem = new int[newArr.length];
	for(int i=0;i<newArr.length;i++) {
	    newmem[i] = newArr[i].val;
	}
	Tour newTour = new Tour(newmem);
	this.root = newTour.root;
    }
    //Better insertion algo
    public void insertEff(int e) {
	//To avoid ArrayOutOfBoundsException , increase members length
	Node[] newArr = new Node[this.members.length+1];
	int index=0;
	for(Node n: this.members) {
	    newArr[index++] = n;
	}
	Node newNode = new Node(e);
	newArr[this.members.length] = newNode;
	this.members = newArr;
	//Match only root and newly added Node to get new root
	this.root = matchAndQual(this.root, newNode);
    }
    public Node matchAndQual(Node a,Node b) {
	Node newParent = new Node();
	newParent.val = (a.val>b.val)?a.val:b.val;
	newParent.left = a;newParent.right=b;
	return newParent;
    }
    public void replaceWinner(int e, Node root) {
	Node temp = root;
	Stack<Node> visited = new Stack<>();
	while(!(temp.right==null&&temp.left==null)) {
	    visited.push(temp);
	    temp = (temp.right.val == root.val)?temp.right:temp.left;
	}
	temp.setVal(e);
	while(!visited.empty()) {
	    rematch(visited.pop());
	}
    }
    //Delete winner using definition in the question
    public void deleteWinner() {
	this.replaceWinner(-1, root);
    }  
    //Tournament sort
    public int[] sort(Tour tree) {
	int[] sorted = new int[this.members.length];
	int index=0;
	while(root.val != -1) {
	    sorted[index++] = tree.root.val;
	    tree.replaceWinner(-1, tree.root);
	}
	return sorted;
    }
    private void rematch(Node parent) {
	if(parent.right==null)return;
	int max = (parent.right.val > parent.left.val)?parent.right.val:parent.left.val;
	parent.setVal(max);
    }
    
    public Tour(int key) {
	this.root = new Node(key);
    }
    
    public Tour(int... elts) {
	int index=0;
	this.members = new Node[elts.length];
	for(int e:elts) {
	    this.members[index++] = new Node(e);
	}
	this.root = makeTree(this.members);
    }
    
    public static void main(String...strings ) {
	Tour tree = new Tour(1,2,2,3,3,5,6,3,4);
//	System.out.println(tree.root.val);
//	tree.replaceWinner(9, tree.root);
	System.out.println(Arrays.asList(tree.members));
	tree.insertEff(2);
	System.out.println(tree.root.val);
	int[] arr = tree.sort(tree);
	for(int i=arr.length-1;i>=0;i--) {
	    System.out.print(arr[i]+" ");
	}
//	System.out.println(tree.root.left.right.right.val);
    }
}

class Node{
    int val;
    Node right;
    Node left;
    
    public Node() {
	super();
	this.val = 0;
	this.left = null;
	this.right = null;
    }
    
    public Node(int e) {
	this.val = e;
	this.right = this.left = null;
    }
    
    public void setLeft(Node n) {
	this.left = n;
    }
    
    public void setRight(Node n) {
	this.right = n;
    }
    
    public void setVal(int e) {
	this.val = e;
    }
    
}