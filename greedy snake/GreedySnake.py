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

if __name__ == '__main__':
    main()
    pygame.quit()
   
   