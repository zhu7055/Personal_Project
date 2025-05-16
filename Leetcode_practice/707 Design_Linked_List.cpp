class MyLinkedList {
public:
//定義鏈表節點結構體
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };
    //初始化鏈表
    MyLinkedList() {
        _dummyHead=new LinkedNode(0);//這裡定義的頭節點是一個虛擬頭節點，而不是真正的鏈表頭節點
        _size=0;
    }
    //獲取到第index個節點數值，如果index是非法數值直接返回-1，注意index是從0開始的，第0個節點就是頭節點
    int get(int index){
        if(index>(_size-1)||index<0)//檢查index是否有再範圍內
        {
            return -1;
        }
        LinkedNode* cur=_dummyHead->next;
        while(index--){//如果--index就會陷入死循環
            cur=cur->next;
        }
        return cur->val;
    }

// 在鏈表最前面插入一個節點，插入完成後，新插入的節點為鏈表的新頭節點
    void addAtHead(int val) {
        LinkedNode* newNode=new LinkedNode(val);
        newNode->next=_dummyHead->next;
        _dummyHead->next=newNode;
        _size++;
    }
    //在鏈表最後面添加一個節點
    void addAtTail(int val) {
        LinkedNode* newNode=new LinkedNode(val);
        LinkedNode* cur=_dummyHead;
        while(cur->next!=nullptr){
            cur=cur->next;
        }
        cur->next=newNode;
        _size++;
    }

//第index個節點前插入node
    void addAtIndex(int index, int val) {
        if(index>_size) return;
        if(index<0)index=0;
        LinkedNode* newNode=new LinkedNode(val);
        LinkedNode* cur=_dummyHead;
        while(index--)
        {
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        _size++;
    }

    //刪除第index個節點，如果index大於等於鍊表的長度，直接return，注意index是從0開始的
    void deleteAtIndex(int index) {
        if(index>=_size||index<0)
        {
            return;
        }
        LinkedNode* cur=_dummyHead;
        while(index--)
        {
            cur=cur->next;
        }
        LinkedNode* tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        //delete命令指示釋放了tmp指針原本所指的那部分內存，
        //被delete後的指針tmp的值(地址)並非就是NULL，而是隨機值。也就是被delete後，
        //如果不再加上一句tmp=nullptr，tmp會成為亂指的野指針
        //如果之後的程序不小心使用了tmp，會指向難以預想的內存空間
        tmp=nullptr;
        _size--;
    }

    //打印鏈表
    void printLinkedList(){
        LinkedNode* cur=_dummyHead;
        while(cur->next!=nullptr)
        {
            cout<<cur->next->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    private:
        int _size;
        LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */