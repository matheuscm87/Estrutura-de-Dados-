import pygame
import numpy as np
import csv
import random
import threading
import time

class Maze:

    WALL = 0
    HALL = 1
    PLAYER = 2
    PRIZE = 3
    PATH = 4  

    def __init__(self):
        self.M = None
        pygame.init()

    def load_from_csv(self, file_path: str):
        with open(file_path, newline='') as csvfile:
            reader = csv.reader(csvfile)
            self.M = np.array([list(map(int, row)) for row in reader])

    def init_player(self):
        while True:
            posx = random.randint(1, self.M.shape[0] - 2)
            posy = random.randint(1, self.M.shape[1] - 2)
            if self.M[posx, posy] == Maze.HALL:
                self.init_pos_player = (posx, posy)
                break

        while True:
            posx = random.randint(1, self.M.shape[0] - 2)
            posy = random.randint(1, self.M.shape[1] - 2)
            if self.M[posx, posy] == Maze.HALL:
                self.M[posx, posy] = Maze.PRIZE
                break

    def get_init_pos_player(self):
        return self.init_pos_player

    def is_free(self, pos):
        if self.M[pos[0], pos[1]] in [Maze.HALL, Maze.PRIZE]:
            return True
        return False

    def find_prize(self, pos):
        return self.M[pos[0], pos[1]] == Maze.PRIZE

    def mov_player(self, pos):
        if self.M[pos[0], pos[1]] == Maze.HALL:
            self.M[pos[0], pos[1]] = Maze.PLAYER

    def run(self):
        th = threading.Thread(target=self._display)
        th.start()

    def _display(self, cell_size=15):
        rows, cols = self.M.shape
        width, height = cols * cell_size, rows * cell_size
        screen = pygame.display.set_mode((width, height))
        pygame.display.set_caption("Labirinto")

        BLACK = (0, 0, 0)
        GRAY = (192, 192, 192)
        BLUE = (0, 0, 255)
        GOLD = (255, 215, 0)
        GREEN = (0, 255, 0)

        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    pygame.quit()

            screen.fill(BLACK)

            for y in range(rows):
                for x in range(cols):
                    if self.M[y, x] == Maze.WALL:
                        color = BLACK
                    elif self.M[y, x] == Maze.HALL:
                        color = GRAY
                    elif self.M[y, x] == Maze.PLAYER:
                        color = BLUE
                    elif self.M[y, x] == Maze.PRIZE:
                        color = GOLD
                    elif self.M[y, x] == Maze.PATH:
                        color = GREEN

                    pygame.draw.rect(screen, color, (x * cell_size, y * cell_size, cell_size, cell_size))

            pygame.display.flip()
            time.sleep(0.05) 

    def solve_maze(self):
        stack = []
        visited = set()

        start_pos = self.get_init_pos_player()
        stack.append(start_pos)

        while stack:
            current_pos = stack.pop()

            if current_pos in visited:
                continue

            visited.add(current_pos)

            if self.find_prize(current_pos):
                print("Prêmio encontrado em:", current_pos)
                return True

            if self.M[current_pos[0], current_pos[1]] != Maze.PLAYER:
                self.M[current_pos[0], current_pos[1]] = Maze.PATH

            directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
            for d in directions:
                new_pos = (current_pos[0] + d[0], current_pos[1] + d[1])
                if self.is_free(new_pos) and new_pos not in visited:
                    stack.append(new_pos)

        print("Prêmio não encontrado!")
        return False
