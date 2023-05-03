import numpy as np

# Define the dimensions of the 3D array
petabyte = 10**15
dim_x = int((petabyte / 8)**(1/3))  # Assuming 8 bytes per value
dim_y = int((petabyte / 8)**(1/3))
dim_z = int((petabyte / 8)**(1/3))

# Create the 3D array
memory = np.zeros((dim_x, dim_y, dim_z))

# Define the values of x, y, and z
x = 1
y = 2
z = 3

# Store the values in memory
memory[dim_x//2, dim_y//2, dim_z//2] = (x, y, z)

# Retrieve the values from memory
x_new, y_new, z_new = memory[dim_x//2, dim_y//2, dim_z//2]

print("x_new:", x_new)
print("y_new:", y_new)
print("z_new:", z_new)
