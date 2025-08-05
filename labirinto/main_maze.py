from maze import Maze

maze_csv_path = "labirinto1.txt"
maze = Maze()

maze.load_from_csv(maze_csv_path)
maze.run()
maze.init_player()
maze.mov_player(maze.get_init_pos_player())

maze.solve_maze()
