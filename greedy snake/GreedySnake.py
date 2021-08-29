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

direction = 'RIGHT'
change_to = direction
   
# snake initial
'''
snake_pos = [300, 300]
snake_body = [[300, 300], [290, 300], [280, 300]]
direction = 'RIGHT'
change_to = direction
speed = 15


# gain point randomly
point = [random.randrange(1, (H//10)) * 10, random.randrange(1, (W//10)) * 10]
point_gained = True
'''

# frame controll
fps_controller = pygame.time.Clock()
flag = 0
#——————————————————————————————————————————————————————————————#
# start code body

# setting class

# make Snake class
class Snake:
    def __init__(self):
        snake_pos = [300, 300]
        snake_body = [[300, 300], [290, 300], [280, 300]]
        speed = 15
        #pass
    
    def make_sure(self):
        #global direction #set global variable for defualt moving direction 
        #global change_to #set global variable for get moving direction 
        
        global direction 
        global change_to 
        if change_to == 'UP' and direction != 'DOWN':
            direction = 'UP'
        if change_to == 'DOWN' and direction != 'UP':
            direction = 'DOWN'
        if change_to == 'LEFT' and direction != 'RIGHT':
            direction = 'LEFT'
        if change_to == 'RIGHT' and direction != 'LEFT':
            direction = 'RIGHT'
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
        if direction == 'UP':
           snake_pos[1] -= 10
        if direction == 'DOWN':
           snake_pos[1] += 10
        if direction == 'LEFT':
           snake_pos[0] -= 10
        if direction == 'RIGHT':
           snake_pos[0] += 10

class Point:
    def __init__(self):
        point = [random.randrange(1, (H//10)) * 10, random.randrange(1, (W//10)) * 10]
        point_gained = True
    # update for the next point generate
    def spawing(self):
        #global point_gained
        #global point
        if not point_gained:
            self.point = [random.randrange(1, (H//10)) * 10, random.randrange(1, (W//10)) * 10] # 在視窗內隨機生成
        self.point_gained = True
      
#—————————useful function————————————————————————————————————————#

# show_Score
def show_Score(choice, color, font, size):

        global score
        score_font = pygame.font.SysFont(font, size)
        score_surface = score_font.render('The Score : ' + str(score), True, color)
        score_rect = score_surface.get_rect()
        if choice == 1:
            score_rect.midtop = (H/10, 15)
        else:
            score_rect.midtop = (H/2, W/2)
        game_window.blit(score_surface, score_rect)

# restart
def restart(color, font, size):
        restart_font = pygame.font.SysFont(font, size)
        restart_surface = restart_font.render('press ANY_KEY to restart', True, color)
        restart_rect = restart_surface.get_rect()
        restart_rect.midtop = (H/2, W/1.4)
        game_window.blit(restart_surface, restart_rect)
    
#gameover
def gameover(snake, points):
        global score
        global red
        gameoverFont = pygame.font.SysFont('arial.ttf',54)
        gameoverSurf = gameoverFont.render('Game Over!',True,red)
        gameoverRect = gameoverSurf.get_rect()
        #position
        gameoverRect.midtop = (H/2, W/4)
        game_window.fill(black)
        game_window.blit(gameoverSurf, gameoverRect)
        show_Score(0,red,'times',20)
        restart(blue,'times',30)
        pygame.display.flip() # update window
        
        while True:
            for event in pygame.event.get():

                if event.type == pygame.QUIT:
                    time.sleep(1) # pause
                    pygame.quit()
                

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_SPACE:
                        # back to initial
                        snake = Snake()
                        points = Point()

                        time.sleep(1) # pause
                        pygame.display.update()
                        main()
                        break
            
#————————— main function————————————————————————————————————————#

def main():
    pygame.init() 
    
    global flag

    while True:   
        game_window.fill(black) # window color
        snake = Snake()
        point = Point()
        for event in pygame.event.get():   # event
            

            if  event.type == pygame.QUIT: # x to quit
                pygame.display.quit()
                pygame.quit()
                
            elif event.type == pygame.KEYDOWN: # other keys
                # esc to quit
                if event.key == pygame.K_ESCAPE: 
                    pygame.quit()
                    exit(0)

            # press w s a d / ↑ ↓ ← → to move
                if event.key == pygame.K_UP or event.key == ord('w'):
                    snake.change_to = 'UP'                                    # 先儲存到預計移動方向
                if event.key == pygame.K_DOWN or event.key == ord('s'):
                    snake.change_to = 'DOWN'
                if event.key == pygame.K_LEFT or event.key == ord('a'):
                    snake.change_to = 'LEFT'
                if event.key == pygame.K_RIGHT or event.key == ord('d'):
                    snake.change_to = 'RIGHT'
                
        
        # call function
        snake.make_sure()
        snake.moving()
        snake.growing()
        point.spawing()

        # print snake
        for pos in snake_body:
            # Snake body
            # .draw.rect(window, color, xy position)
            # xy_pos -> .Rect(x, y, size_x, size_y)
            pygame.draw.rect(game_window, green, pygame.Rect(pos[0], pos[1], 10, 10))

        # drew point using Rect
        pygame.draw.rect(game_window, white, pygame.Rect(point[0], point[1], 10, 10))


        # Game Over 
        # Hit frmae
        if snake_pos[0] < 0 or snake_pos[0] > H-10:
            gameover()
        if snake_pos[1] < 0 or snake_pos[1] > W-10:
            gameover()
        # hit snake
        for block in snake_body[1:]:
            if snake_pos[0] == block[0] and snake_pos[1] == block[1]:
                gameover()
            show_Score(1, white, 'consolas', 20)

        # window update
        pygame.display.update()

        # fps for hard-mode
        global speed
        accelerate()
        fps_controller.tick(speed)


if __name__ == '__main__':
    main()
    pygame.quit()
   
   