import os

def clear_screen():
	command = 'clear'
	if os.name in ('nt', 'dos'):
		command = 'cls'
	os.system(command)

class Canvas:

	def __init__(self, size_x, size_y):
		self.size_x = size_x
		self.size_y = size_y
		self.array = []
		self.initialize_array()

	def initialize_array(self):
		for y in range(self.size_y):
			new_array = []
			for x in range(self.size_x):
				new_array.append(0)
			self.array.append(new_array)
	
	def get_pixel(self, x, y):
		return self.array[y][x]

	def write_pixel(self, x, y):
		self.array[y][x] = 1
	
	def clear_pixel(self, x, y):
		self.array[y][x] = 0

	def print_canvas(self):
		clear_screen()
		print("  ", end="")
		for x in range(self.size_x):
			print(f"{x:2}", end="")
		print("")
		for y in range(self.size_y):
			print(f"{y:2}", end="")
			for x in range(self.size_x):
				if self.array[y][x]:
					print(" X", end="")
				else:
					print(" -", end="")
			print("")


canvas = Canvas(17, 18)
canvas.write_pixel(10, 11)
canvas.write_pixel(3, 4)
canvas.write_pixel(5, 9)
canvas.print_canvas()