import matplotlib.pyplot as plt
import pandas as pd
import os

import numpy as np

files = ['FullGraph.csv', 'ConnectedGraph.csv', 'TreeGraph.csv']
graph_types = ['Полные графы', 'Связные графы', 'Деревья']
algorithms = ['Алгоритм Дейкстры', 'Алгоритм Беллмана-Форда', 'Алгоритм Флойда-Уоршелла', 'Алгоритм Джонсона']

for algo in algorithms:
    plt.figure(figsize=(14, 6))

    plt.subplot(1, 2, 1)
    for file, graph_type in zip(files, graph_types):
        if os.path.exists(file):
            data = pd.read_csv(file, header=0)
            algo_data = data[data['algorithm_name'] == algo]
            algo_data['execution_time'] = algo_data['execution_time'].astype(float)  # Преобразование в числовой формат
            plt.plot(algo_data['number_of_vertexes'], algo_data['execution_time'], label=graph_type)
    plt.xlabel('Количество вершин')
    plt.ylabel('Время выполнения, нс')
    plt.title(f'{algo} - зависимость времени от числа вершин')
    plt.legend()

    plt.subplot(1, 2, 2)
    for file, graph_type in zip(files, graph_types):
        if os.path.exists(file):
            data = pd.read_csv(file, header=0)
            algo_data = data[data['algorithm_name'] == algo]
            algo_data['execution_time'] = algo_data['execution_time'].astype(float)  # Преобразование в числовой формат
            plt.plot(algo_data['number_of_edges'], algo_data['execution_time'], label=graph_type)
    plt.xlabel('Количество ребер')
    plt.ylabel('Время выполнения, нс')
    plt.title(f'{algo} - зависимость времени от числа ребер')
    plt.legend()

    plt.tight_layout()
    plt.savefig(f'{algo}_comparison.png', dpi=300)
    plt.close()

    for file, graph_type in zip(files, graph_types):
        if os.path.exists(file):
            data = pd.read_csv(file, header=0)
            plt.figure(figsize=(10, 5))
            for algo in algorithms:
                algo_data = data[data['algorithm_name'] == algo]
                algo_data['execution_time'] = algo_data['execution_time'].astype(float)  # Преобразование в числовой формат
                plt.plot(algo_data['number_of_vertexes'], algo_data['execution_time'], label=algo)
            plt.xlabel('Количество вершин')
            plt.ylabel('Время выполнения, нс')
            plt.title(f'Сравнение алгоритмов по вершинам на {graph_type}')
            plt.legend()
            plt.tight_layout()
            plt.savefig(f'{graph_type}_vertexes.png', dpi=300)
            plt.close()

    for file, graph_type in zip(files, graph_types):
        if os.path.exists(file):
            data = pd.read_csv(file, header=0)
            plt.figure(figsize=(10, 5))
            for algo in algorithms:
                algo_data = data[data['algorithm_name'] == algo]
                algo_data['execution_time'] = algo_data['execution_time'].astype(float)  # Преобразование в числовой формат
                plt.plot(algo_data['number_of_edges'], algo_data['execution_time'], label=algo)
            plt.xlabel('Количество ребер')
            plt.ylabel('Время выполнения, нс')
            plt.title(f'Сравнение алгоритмов по ребрам на {graph_type}')
            plt.legend()
            plt.tight_layout()
            plt.savefig(f'{graph_type}_edges.png', dpi=300)
            plt.close()
