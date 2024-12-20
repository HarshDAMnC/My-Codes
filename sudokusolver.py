import numpy as np

#creating the board
board=[
    [9,1,0,0,5,0,3,7,0],
    [0,0,0,8,3,9,5,0,0],
    [3,5,0,0,0,1,0,9,0],
    [0,0,0,0,0,0,0,5,4],
    [7,0,4,5,8,0,0,0,9],
    [5,0,0,0,0,0,8,0,7],
    [0,6,5,0,0,0,9,0,3],
    [8,0,0,0,9,0,0,0,5],
    [0,0,0,0,1,5,7,0,0]
] 
row,col=0,0
count=1
def safe_place(board,row,col,count):
   
    #checking safe place row wise
    for i in range(9):
        if board[i][col]==count:
            return False
    #checking safe place column wise
    for j in range(9):
        if board[row][j]==count:
            return False
    #checking the 3*3 matrix
    new_row=row-row%3
    new_col=col-col%3
    for k in range(3):
        for l in range(3):
            if board[k+new_row][l+new_col]==count:
                return False
    return True
#placing the numbers in safe positions
def place_number(board,row,col,count):
     #goes to next row if all columns are filled
    if col>=9:
            col=0
            row+=1
        #indication of task completion
    if row>=9:
            print(board)
            print('task successfuly completed!!!')
            return True
    if board[row][col]>0:
         return place_number(board,row,col+1,count)
    #starting from the 0th column if last column is reached
    for count in range(1,10):
       
        #checking safe place
        if safe_place(board,row,col,count)==True:
            board[row][col]=count
            print(count)
        #recursively calling the function
            if place_number(board,row,col+1,count):
                return True
            #backtracking- it checks if the next column is safe for count==1-9, if yes it prints count
            #if no, the bprevious one becomes 0 and it continues the for loop of count from where it
            #had stopped, if that loop also ends unsuccessfully, it goes to the previous col, as it was 
            #also a reslut of forward checking
            board[row][col]=0
#first call
place_number(board,row,col,count)
#by Harsh Shah

            
        

    
    
