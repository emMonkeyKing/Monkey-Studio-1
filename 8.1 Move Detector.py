import random
import pygame
import sys

SIZE = 640, 396
HEIGHT = 640
FPS = 60

pygame.init()
screen = pygame.display.set_mode(SIZE, 0, 32)
pygame.display.set_caption("Event")
clock = pygame.time.Clock()
font = pygame.font.SysFont("Paris 2024", 25)
font_height = font.get_linesize()
event_list = []
line_num = SIZE[1] // font_height

running = True

while running:
    event = pygame.event.wait()
    event_list.append(str(event))
    event_text = event_list[-line_num:]

    screen.fill((54, 59, 64))
    y = SIZE[1]-font_height
    
    for text in reversed(event_list):
        rgb = tuple((random.randint(0, 255) for i in range (3)))
        screen.blit(font.render(text, True, rgb), (0, y))
        y -= font_height

    pygame.display.update()
