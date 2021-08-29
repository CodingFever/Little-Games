import pygame, sys, time, random


#inital global variable
#——————————————————————————————————————————————————————————————#
# Using tuple to fix color set
# color = (R,G,B)
black = (0, 0, 0)
white = (255, 255, 255)
red   = (255, 0, 0)
green = (0, 255, 0)
blue  = (0, 0, 255)

# frame size
H = 800
W = 600
game_window = pygame.display.set_mode((H, W))
pygame.display.set_caption("snake")

#score initial
score = 0
   
# snake initial
'''
snake_pos = [300, 300]
snake_body = [[300, 300], [290, 300], [280, 300]]
direction = 'RIGHT'
change_to = direction
speed = 15


# gain point randomly
point = [random.randrange(1, (H//10)) * 10, random.randrange(1, (W//10)) * 10]

'''
point_gained = True
# frame controll
fps_controller = pygame.time.Clock()
flag = 0
#——————————————————————————————————————————————————————————————#
# start code body
# make Snake class
class Snake:
    def __init__(self):
        snake_pos = [300, 300]
        snake_body = [[300, 300], [290, 300], [280, 300]]
        direction = 'RIGHT'
        change_to = direction
        speed = 15
        #pass
    
    def make_sure(self):
        #global direction #set global variable for defualt moving direction 
        #global change_to #set global variable for get moving direction 
        
        if self.change_to == 'UP' and self.direction != 'DOWN':
            self.direction = 'UP'
        if self.change_to == 'DOWN' and self.direction != 'UP':
            self.direction = 'DOWN'
        if self.change_to == 'LEFT' and self.direction != 'RIGHT':
            self.direction = 'LEFT'
        if self.change_to == 'RIGHT' and self.direction != 'LEFT':
            self.direction = 'RIGHT'

    #if hit point, add 1 more block in the snake body
    def growing(self):
        #global snake_body
        global score
        global point_gained
        global flag
        self.snake_body.insert(0, list(self.snake_pos))
        if self.snake_pos[0] == point[0] and self.snake_pos[1] == point[1]:
           score += 1
           flag = 1
           point_gained = False
        else:
           self.snake_body.pop()


    def moving(self):
        #global direction
        #global snack_pos
        if self.direction == 'UP':
           self.snake_pos[1] -= 10
        if self.direction == 'DOWN':
           self.snake_pos[1] += 10
        if self.direction == 'LEFT':
           self.snake_pos[0] -= 10
        if self.direction == 'RIGHT':
           self.snake_pos[0] += 10

class Point:
    def __init__(self):
        point = [random.randrange(1, (H//10)) * 10, random.randrange(1, (W//10)) * 10]
        
    # update for the next point generate
    def spawing(self):
        global point_gained
        #global point
        if not point_gained:
            self.point = [random.randrange(1, (H//10)) * 10, random.randrange(1, (W//10)) * 10] # 在視窗內隨機生成
        point_gained = True
        
 

if __name__ == '__main__':
    main()
    pygame.quit()
   
   