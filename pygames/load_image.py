import pygame


def load_image(imgname="dog.png"):
    """
    Function to load image
    """
    return pygame.image.load('data/' + imgname)

def main():
    # initialize pygame
    pygame.init()
    screen = pygame.display.set_mode((1024, 768))
    # load the png image
    dogimg = load_image("dog2.png")
    game_loop = True
    # game llop
    while game_loop:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_loop = False
            # draw the png image
            screen.blit(dogimg, (0,0))
            pygame.display.flip()
    # bye bye
    pygame.quit()

if __name__ == "__main__":
    main()
