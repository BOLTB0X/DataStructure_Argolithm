def getPrimaryNum_Eratos(number): 
    number_visited = [True] * (number + 1) 
    n=len(number_visited)
    for i in range(2, (n // 2) + 1): 
        if number_visited[i] == True: 
            for j in range(i+i, number, i): #배수들을 지워준다
                number_visited[j] = False 
    return [i for i in range(2, number) if number_visited[i] == True]

print(getPrimaryNum_Eratos(120))