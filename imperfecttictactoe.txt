#!/usr/bin/python3.8
from random import shuffle

play = True
def display_board(board):
    print(board[1]+'|'+board[2]+'|'+board[3])
    print(board[4]+'|'+board[5]+'|'+board[6])
    print(board[7]+'|'+board[8]+'|'+board[9])
    
def human_move(board):
    move = 100
    while move < 1 or move > 9:
        try:
            move = int(input('Enter a number [1-9]: '))
        except ValueError:
            move = 100
        if (move >= 1 and move <= 9 and board[move] == ' '):
            board[move] = 'x'
        else:
            print('Invalid move. Try again')
    add_to_paths(move,0)
    
def add_to_paths(move,player):
    global win_paths
    global best_move
    global assess_move
    for path in paths[move]:
        win_paths[player][path] += 1
        for x in (0,2):
            if (win_paths[x][path] > 0 and win_paths[x+1][path] > 0):
                win_paths[x][path] = -1
                win_paths[x+1][path] = -1
    for path in (1,2,3,4,5,6,7,8):
        if (win_paths[3][path] == 3):
            assess_move[0] += 1024
        if (win_paths[0][path] == 2 and win_paths[2][path] == -1):
            assess_move[0] += 64
        if (win_paths[3][path] == 2):
            assess_move[0] += 16
        if (win_paths[0][path] == 1 and win_paths[2][path] == -1):
            assess_move[0] += 4
        if (win_paths[3][path] == 1):
            assess_move[0] += 1            
        win_paths[3][path] = win_paths[1][path]
        win_paths[2][path] = win_paths[0][path] 
    if (assess_move[0] > assess_move[1]):
        assess_move[1] = assess_move[0]  
        best_move = [move]
    elif (assess_move[0] == assess_move[1]):
        best_move += [move]
    assess_move[0] = 0    
    
def computer_move(board):
    global best_move
    global assess_move
    for move in (1,2,3,4,5,6,7,8,9):
        if (board[move] == ' '):
            add_to_paths(move,3)
    shuffle(best_move)
    board[best_move[0]] = 'o'
    add_to_paths(best_move[0],1)
    assess_move = [0,0]
    
def game_over():
    space = 0
    for path in (1,2,3,4,5,6,7,8):
        if (win_paths[0][path] == 3):
            who_won[1] = True
        elif (win_paths[1][path] == 3):
            who_won[2] = True
        if (test_board[path] == ' '):
            space += 1
    if (space == 0 and test_board[9] != ' '):
        who_won[0] = True
    for x in (0,1,2):
        if (who_won[x] == True):
            print(f'{x}p won')
            return True
            
if (play == True):
    best_move = [0]
    assess_move = [0,0]
    paths = ['#',(1,4,7),(1,5),(1,6,8),(2,4),(2,5,7,8),(2,6),(3,4,8),(3,5),(3,6,7)] 
    test_board = ['#'] + [' '] * 9
    win_paths = [['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0],['#',0,0,0,0,0,0,0,0]]
    wins = [['#'] + [0] *8] *4
#    print(win_paths)
#    print(wins)
    display_board(test_board)
    who_won = [False,False,False]
    while (game_over() != True):
        human_move(test_board)
        if (game_over() == True):
            display_board(test_board)
            break
        computer_move(test_board)
        display_board(test_board)
    play = input('Play again? (Y or N): ') == 'Y'       
