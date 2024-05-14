
class BST_by_name {
    struct node {
        node *left, *right;
        t data;
        node() {
            data = 0;
            left = right = nullptr;
        }
    };
private:
    node *root;
    node *insert(node *pn, t n) {
        if (pn == nullptr) {
            node *newn = new node;
            newn->data = n;
            pn = newn;
        } else if (n < pn->data) {
            pn->left = insert(pn->left, n);
        } else {
            pn->right = insert(pn->right, n);
        }
        return pn;
    }
    void pre(node *te) {
        if (te == nullptr) {
            return;
        }
        cout << te->data << " ";
        pre(te->left);
        pre(te->right);
    }

    void asc_by_name_(node *te) {
        if (te == nullptr) {
            return;
        }
        asc_by_name(te->left);
        cout << te->data << " ";
        asc_by_name(te->right);
    }
    void desc_by_name (node *te){
        if (te == nullptr) {
            return;
        }
        desc_by_name(te->right);
        cout << te->data << " ";
        desc_by_name(te->left);

    };

    void post(node *te) {
        if (te == nullptr) {
            return;
        }
        post(te->left);
        post(te->right);
        cout << te->data << " ";
    }
    node *search(node *r, t item) {
        if (r == nullptr)
            return nullptr;
        else if (r->data == item) {
            return r;
        } else if (item < r->data) {
            return search(r->left, item);
        } else {
            return search(r->right, item);
        }
    }
    node *mn(node *r) {
        if (r == nullptr) {
            return nullptr;
        }
        if (r->left == nullptr) {
            return r;
        } else
            return mn(r->left);
    }

    node *mx(node *r) {
        if (r == nullptr) {
            return nullptr;
        }
        if (r->right == nullptr) {
            return r;
        } else
            return mx(r->right);
    }

    node *Delete(node *r, t item) {
        if (r == nullptr) {
            return nullptr;
        } else if (item < r->data) {
            r->left = Delete(r->left, item);
        } else if (item > r->data) {
            r->right = Delete(r->right, item);
        } else {
            if (r->right == nullptr && r->left == nullptr) {
                delete r;
                r = nullptr;
            } else if (r->left == nullptr) {
                node *temp = r;
                r = r->right;
                delete temp;
            } else if (r->right == nullptr) {
                node *temp = r;
                r = r->left;
                delete temp;
            } else {
                node *temp = mn(r->right);
                r->data = temp->data;
                r->right = Delete(r->right, temp->data);
            }
        }
        return r;
    }
public:
    BST() {
        root = nullptr;
    }
    bool search(t item) {
        node *fr = search(root, item);
        return !(fr == nullptr);
    }
    void insert(t item) {
        root = insert(root, item);
    }
    t min_element(){
        return mn(root)->data;
    }
    t max_element(){
        return mx(root)->data;
    }
    bool Isempty(){
        return root== nullptr;
    }
    void Pre_order(){
        pre(root);
    }
    void Post_order(){
        post(root);
    }
    void IN_order(){
        in(root);
    }
    void Delete_node(t value){
        root= Delete(root,value);
    }
};
