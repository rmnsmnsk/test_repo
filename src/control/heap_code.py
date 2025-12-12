class BinNode:
    def __init__(self, prior, data=None):
        self.prior = prior
        self.data = data
        self.rank = 0
        self.up = None
        self.down = None
        self.right = None

class BinHeap:
    def __init__(self):
        self.root_list = None
    
    def insert(self, prior, data=None):
        new_node = BinNode(prior, data)
        temp_heap = BinHeap()
        temp_heap.root_list = new_node
        self.root_list = self.merge(self.root_list, temp_heap.root_list)
        return new_node  # для доп тстов
    def getMinimum(self):
        if not self.root_list:
            return None
        
        cur = self.root_list
        min_node = cur
        
        while cur:
            if cur.prior < min_node.prior:
                min_node = cur
            cur = cur.right
        
        return (min_node.prior, min_node.data)
    
    def extractMin(self):
        if not self.root_list:
            return None

        prev_min = None
        min_node = self.root_list
        next_node = self.root_list.right
        walk = self.root_list
        
        while next_node:
            if next_node.prior < min_node.prior:
                min_node = next_node
                prev_min = walk
            walk = next_node
            next_node = next_node.right
        
        if prev_min is None:
            self.root_list = min_node.right
        else:
            prev_min.right = min_node.right
        
        reversed_kids = None
        kid = min_node.down
        
        while kid:
            next_kid = kid.right
            kid.right = reversed_kids
            reversed_kids = kid
            kid = next_kid
        
        kids_heap = BinHeap()
        kids_heap.root_list = reversed_kids
        self.root_list = self.merge(self.root_list, kids_heap.root_list)
        
        return (min_node.prior, min_node.data)
    
    def merge(self, list1, list2):
        if list1 is None:
            return list2
        if list2 is None:
            return list1
        
        merged_head = None
        if list1.rank <= list2.rank:
            merged_head = list1
            list1 = list1.right
        else:
            merged_head = list2
            list2 = list2.right
        
        current = merged_head

        while list1 and list2:
            if list1.rank <= list2.rank:
                current.right = list1
                list1 = list1.right
            else:
                current.right = list2
                list2 = list2.right
            current = current.right
        
        if list1:
            current.right = list1
        else:
            current.right = list2
        
        prev = None
        x = merged_head
        next_x = x.right
        
        while next_x:
            if (x.rank != next_x.rank) or (next_x.right and next_x.right.rank == x.rank):
                prev = x
                x = next_x
            else:
                if x.prior <= next_x.prior:
                    x.right = next_x.right
                    self.link(next_x, x)
                else:
                    if prev is None:
                        merged_head = next_x
                    else:
                        prev.right = next_x
                    self.link(x, next_x)
                    x = next_x
            next_x = x.right
        
        return merged_head
    
    def link(self, child_node, parent_node):
        child_node.up = parent_node
        child_node.right = parent_node.down
        parent_node.down = child_node
        parent_node.rank += 1
    
    def decreaseKey(self, node, new_prior):
        if new_prior > node.prior:
            raise ValueError("Новый приоритет больше текущего")
        
        node.prior = new_prior
        parent = node.up
        
        while parent and node.prior < parent.prior:
            node.prior, parent.prior = parent.prior, node.prior
            node.data, parent.data = parent.data, node.data
            node = parent
            parent = node.up
    
    def delete(self, node):
        self.decreaseKey(node, float('-inf'))
        self.extractMin()

if __name__ == "__main__":
    heap = BinHeap()
    
    heap.insert(5, "A")
    heap.insert(3, "B")
    heap.insert(8, "C")
    heap.insert(1, "D")
    
    print("Min:", heap.getMinimum())
    
    print("\nExtract:")
    while heap.root_list:
        print(heap.extractMin())