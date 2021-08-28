from typing import Sized
import pygame
import random
#creat a rectangle background for the game
pygame.init()
W = 800
H = 600

size = (W,H)
window = pygame.display.set_mode(size)
pygame.display.set_caption("snake")