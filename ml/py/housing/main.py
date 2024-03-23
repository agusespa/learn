import pandas as pd

data_file_path = "./data/melb_data.csv"

melb_data = pd.read_csv(data_file_path)

print(melb_data.describe())
