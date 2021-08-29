import pygame, sys, time, random


#inital
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
snake_pos = [300, 300]
snake_body = [[300, 300], [290, 300], [280, 300]]
direction = 'RIGHT'
change_to = direction
speed = 15

# gain point
point = [random.randrange(1, (H//10)) * 10, random.randrange(1, (W//10)) * 10]
point_gained = True

# frame controll
fps_controller = pygame.time.Clock()
flag = 0
#——————————————————————————————————————————————————————————————#


# accelerate
def accelerate():
    global score
    global speed
    global flag
    if speed <= 27 and flag == 1 :
        speed += 1
        flag = 0
# show_Score
def show_Score(choice, color, font, size):

        global score
        score_font = pygame.font.SysFont(font, size)
        score_surface = score_font.render('Score : ' + str(score), True, color)
        score_rect = score_surface.get_rect()
        if choice == 1:
            score_rect.midtop = (H/10, 15)
        else:
            score_rect.midtop = (H/2, W/2)
        game_window.blit(score_surface, score_rect)

# 顯示"重新開始"文字
def restart(color, font, size):
        restart_font = pygame.font.SysFont(font, size)
        restart_surface = restart_font.render('press SPACE to restart', True, color)
        restart_rect = restart_surface.get_rect()
        restart_rect.midtop = (H/2, W/1.4)
        game_window.blit(restart_surface, restart_rect)
    
#gameover
def gameover():
        global score
        global red
        gameoverFont = pygame.font.SysFont('arial.ttf',54)
        gameoverSurf = gameoverFont.render('Game Over!',True,red)
        gameoverRect = gameoverSurf.get_rect()
        gameoverRect.midtop = (H/2, W/4)
        game_window.fill(black)
        game_window.blit(gameoverSurf, gameoverRect)
        show_Score(0,red,'times',20)
        restart(blue,'times',30)
        pygame.display.flip() # 更新視窗
        
        while True:
            for event in pygame.event.get():

                if event.type == pygame.QUIT:
                    time.sleep(1) # 停留一秒
                    pygame.quit()
                

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_SPACE:
                        # 更新全域變數到初始狀態
                        global snake_pos
                        global snake_body
                        global direction
                        global change_to
                        global speed
                        speed = 15
                        score = 0
                        snake_pos = [300, 300]
                        snake_body = [[300, 300], [290, 300], [280, 300]]
                        direction = 'UP'
                        change_to = direction
                        time.sleep(1) # 停留一秒
                        pygame.display.update()
                        main()
                        break
            
   
# Snake class
class Snake:
    def __init__(self):
        pass
        
    # 確認當前移動方向 與 控制者執行方向 是否相反
    def make_sure(self):
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

    # 蛇身體增長
    def growing(self):
        global snake_body
        global score
        global point_gained
        global flag
        snake_body.insert(0, list(snake_pos))
        if snake_pos[0] == point[0] and snake_pos[1] == point[1]:
           score += 1
           flag = 1
           point_gained = False
        else:
           snake_body.pop()
    # 移動
    def moving(self):
        global direction
        global snack_pos
        if direction == 'UP':
           snake_pos[1] -= 10
        if direction == 'DOWN':
           snake_pos[1] += 10
        if direction == 'LEFT':
           snake_pos[0] -= 10
        if direction == 'RIGHT':
           snake_pos[0] += 10


 
# 吃的點點
class Point:

    def __init__(self):
        pass
    # 更新食物位置
    def spawing(self):
        global point_gained
        global point
        if not point_gained:
            point = [random.randrange(1, (H//10)) * 10, random.randrange(1, (W//10)) * 10] # 在視窗內隨機生成
        point_gained = True
        
# main function
def main():
    pygame.init() # 初始化
    global change_to
    global snake_body
    global snake_pos
    global flag

    while True:   
        game_window.fill(black) # 視窗顏色

        for event in pygame.event.get():   # 事件
            if  event.type == pygame.QUIT: # 按叉離開
                pygame.display.quit()
                pygame.quit()
                
            elif event.type == pygame.KEYDOWN: # 其餘按鍵
                # 按 esc 跳出遊戲
                if event.key == pygame.K_ESCAPE: 
                    pygame.quit()
                    exit(0)

            # w s a d 或 ↑ ↓ ← → 移動
                if event.key == pygame.K_UP or event.key == ord('w'):
                    change_to = 'UP'                                    # 先儲存到預計移動方向
                if event.key == pygame.K_DOWN or event.key == ord('s'):
                    change_to = 'DOWN'
                if event.key == pygame.K_LEFT or event.key == ord('a'):
                    change_to = 'LEFT'
                if event.key == pygame.K_RIGHT or event.key == ord('d'):
                    change_to = 'RIGHT'
                
        snake = Snake()
        point = Point()
        # 呼叫函示(確認方向、移動、吃到點伸長、更新點點位置)
        snake.make_sure()
        snake.moving()
        snake.growing()
        point.spawing()

        # print snake
        for pos in snake_body:
            # Snake body
            # .draw.rect(視窗, 顏色, xy座標)
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
   
   