#pragma once
#include "cmpslib19.h"
#include "easylogging++.h"


template <class T>
class BST
{
    class TreeNode
    {
        public:
            T data;
            TreeNode *left;
            TreeNode *right;
            TreeNode(T val)
            {
                data=val;
                left=nullptr;
                right=nullptr;
            }
    };

    private:
    TreeNode *root;

    // private helper function for insert. It will see if the value belongs in the left or
    // right subtree. If the correct subtree is currently nullptr , it will allocate a
    // new node and insert it there. Otherwise, it will recursively call
    // insertSubtree on that subtree.
    // return type bool, was the insert successful
    bool insertSubtree(TreeNode * subtree, T elem)
    {
        LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
        // if this node already has the value in it that we want to store
        // return false
        TreeNode *nodePtr = new TreeNode(elem);
        if(subtree->data == elem)
        {
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: false " << endl;
            return false;
        }
        // if the value to insert is greater than the value in the current node
        // go down the right side.. if the right pointer is nullptr add
        // the new node there, if its not nullptr then call insertSubtree
        // with the right pointer
        else if(elem > subtree->data)
        {
            if(subtree->right == nullptr)
                subtree->right = nodePtr;
            else
                insertSubtree(subtree->right, elem);
        }
        // if the value to insert is less than the value in the current node ( else ) 
        // use the same logic for the left side
        else if(elem < subtree->data)
        {
            if(subtree->left == nullptr)
                subtree->left = nodePtr;
            else
                insertSubtree(subtree->left, elem);
        }
        LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning: " << subtree->data << endl;
        return true;
    }

    // private helper function for in-order print traversal. Performs an in-order print
    // traversal by recursively calling inorderSubtree on the left subtree, then
    // printing the data in the current node, then recursively calling
    // inorderSubtree on the right subtree.
    // return type void
    void printSubtree(TreeNode * subtree)
    {
        // if the left node pointer is not nullptr recursively call printSubtree on left
        // print the values from this node
        if(subtree->left != nullptr)
            printSubtree(subtree->left);
        cout << "node: " << subtree << " data: " << subtree->data << " right: " << subtree->right << " left: " << subtree->left << endl;
        // if the right node pointer is not nullptr recursively call printSubtree on right
        if(subtree->right != nullptr)
            printSubtree(subtree->right);
    }

    // a private helper function to remove nodes
    // search down the tree starting at the node provided and if the value is found
    // delete that node
    // parameters:
    // a pointer to a node in the tree
    // a value ( the value to be removed )
    // return type bool
    bool remove(TreeNode* ptr, T elem)
    {
        LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
        TreeNode* parent = ptr;      // parent of node to delete

        /*
           Try to find the element in the tree
           keep moving down the tree to we reach a nullptr pointer or find the value
           use two pointers as you must have a pointer to the parrent Node of the one you
           need to delete in order to proceed
           */
        while (true)
        {
            if (ptr == nullptr)
            {
                // bottom of the tree  and we did not find it

                LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
                LOG(INFO) << "Returning: false" << endl;
                return(false);
            }
            if (ptr->data == elem)
            {
                break;  // found it stop while loop

            }
            if (elem < ptr->data)
            {
                // the value we are looking for is less so go left

                parent = ptr;
                ptr = ptr->left;
            }
            else
            {
                // the value we are looking for is more so go right

                parent = ptr;
                ptr = ptr->right;
            }
        }

        // at this point ptr should point to the node we want to delete

        // and parent should point to the node above it (if if is not the root node)


        /* there are really 3 possible scenarios
           1 the node we want to delete has no chilren , easy
           2 the node we wnat to delte has 1 child , not bad
           3 the node we wand to delete has 2 children, most involved */

        // case 1 , no children

        if (ptr->right == nullptr && ptr->left == nullptr)
        {
            LOG (INFO) <<"Case 1 , no child nodes\n";
            // set the ponter in parrent that curently points to the node we want to delete to nullptr

            if(parent->right==ptr)
            {
                parent->right=nullptr;
            }
            else
            {
                parent->left=nullptr;
            }
            LOG (INFO) << "deleting a node containing " << ptr->data << endl;
            if (ptr == root )
            {
                root = nullptr;
            }
            delete ptr;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: true" << endl;
            return true;
        } // end case 1


        // case 2 , one child node

        if ( ptr->right == nullptr || ptr->left == nullptr) // one is null so there is only one child node

        {
            LOG (INFO) << "Case 2 , one child node\n";
            // set the pointer in the parrent of ptr to point to the child of ptr, so we can delete the node tmp

            ((parent->right == ptr) ? parent->right : parent->left ) =  ( (ptr->right != nullptr) ?  ptr->right: ptr->left);

            // if ptr is the root node we better update the pointer root so it isnt still pointing the node we are going to delete

            if  (root == ptr)
            {
                root  =  ( (ptr->right != nullptr) ?  ptr->right: ptr->left);
            }
            LOG (INFO) << "deleting a node containing " << ptr->data << endl;
            delete ptr;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: true" << endl;
            return true;
        } // endl case 2


        // case 3 is all that is left

        // Two children to this node, need to find replacement node using either

        // inorder successor or inorder predecessor.


        // Inorder precessor is the largest value in the left subtree

        TreeNode* replacement = ptr->left;
        while(replacement->right)
        {
            replacement = replacement->right;
        }

        // copy the data up to the node we were originally wanting to delete

        T temp = replacement->data;
        LOG (INFO) << "Calling remove for a node with a value of " << temp << " but we are atually going to put the value " << temp 
            << " into the node that use to have the value "  << ptr->data << endl;
        remove(ptr,temp);
        ptr->data = temp;
        LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning: true" << endl;
        return true;
    }


    public:
    BST()
    {
        LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
        // set the pointer to the root node to nullptr
        root = nullptr;
        LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    }

    bool empty()
    {
        //if the root node equals the nullptr the tree is empty
        LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning: " << boolalpha << (nullptr == root) << endl;
        return (nullptr == root);
    }




    bool insert(T elem)
    {
        LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
        // if the root node pointer is nullptr then set the root pointer to a new node
        // store the value to inser into that new node and return true
        // otherwise recursively call insertSubtree
        TreeNode *nodePtr = new TreeNode(elem);
        if (root == nullptr)
            root = nodePtr;
        else
            insertSubtree(root, elem);
        LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning: true" << endl;
        return true;
    }



    // Perform an in-order traversal of the tree. This will print all of the tree's
    // values in sorted order.
    void print()
    {
        LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
        // if the root node is not nullptr
        //call printSubtree
        cout << "BST:\nroot:" << root << endl;
        if (nullptr != root )
        {
            printSubtree(root);
        }
        else
        {
            cout << "No Nodes:\n";
        }

        LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    }

    // public function to remove a value from the tree
    // parameter   value to remove
    // return type bool
    bool remove( T elem)
    {
        LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        return remove(root,elem);
    }

};





