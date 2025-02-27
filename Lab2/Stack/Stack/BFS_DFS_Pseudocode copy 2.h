/*****************BFS (Breadth-First Search)**************/
BFS(u)
{
    // Step 1: Khởi tạo
    Khởi tạo queue rỗng;
    enqueue(queue, u); // Đẩy đỉnh u vào hàng đợi
    visited[u] = true; // Đánh dấu là đỉnh u đã được duyệt

    // Step 2: Lặp khi mà hàng đợi vẫn còn phần tử
    while( queue khác rỗng)
	{
        v = queue.front(); // Lấy ra đỉnh ở đầu hàng đợi
        dequeue(queue); // Xóa đỉnh khỏi đầu hàng đợi
        Duyệt đỉnh v;
        
        // Duyệt các đỉnh kề với v mà chưa được duyệt và đẩy vào hàng đợi
        for(int x : ke[v])
		{
            if( !visited[x]) // Nếu x chưa được duyệt
			{ 
                enqueue(queue, x);
                visited[x] = true;
            }
        }
    }
}

/**********DFS-Depth-First Search****************/
// Bat dau duyet tu dinh u
DFS(u)
{
    Duyet Dinh u;
    visited[u] = true; // Danh dau u da dc duyet
    // Duyet cac dinh ke cua dinh u
    for(v : adj[u])
	{
        if(!visited[v]) // Neu v chua duoc duyet
		{ 
            DFS(v);
        }
    }
}

/**********DFS-Depth-First Search using Stack****************/
DFS(u)
{
    Khởi tạo stack rỗng;
    push(stack, u); // Đẩy đỉnh u vào stack
    while(stack khác rỗng)
	{
        v = stack.pop(); // Lấy đỉnh ở đầu stack và xóa khỏi stack
        if(!visited[v])// Nếu đỉnh v chưa được duyệt
		{ 
            Duyệt đỉnh v;
            visited[v] = true; // Đánh dấu đỉnh v là đã được duyệt
            // Đẩy các đỉnh kề với v vào stack
            for(w : adj[v])
			{
                if(!visited[w])
				{
                    push(stack, w);
                }
            }
        }
    }
}

