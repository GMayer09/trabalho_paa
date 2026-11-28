# Trabalho de Projeto e Análise de Algoritmos

## Identificação dos integrantes da equipe
> - **Nome:** Guilherme Mayer Chamse Ddine **RA:** 140656
> - **Nome:** Yuri Gabriel Leandro de Paula **RA:** 139460

## Sobre o projeto
> Este projeto implementa e compara o tempo de execução de 8 algoritmos de ordenação em C++23, medidos com std::chrono::steady_clock em três cenários de entrada:
> - Vetor desordenado (aleatório)
> - Vetor ordenado crescente
> - Vetor ordenado decrescente

## Algoritmos implementados
> - Insertion Sort
> - Shell Sort
> - Bubble Sort
> - Quick Sort
> - Selection Sort
> - Heap Sort
> - Merge Sort
> - Radix Sort

## Estrutura do projeto
```text
trabalho_paa/
├── docs/
│   ├── DescricaoTrabalho.pdf      # Especificação do trabalho
│   └── Relatorio_paa.pdf          # Relatório com análise e resultados
├── include/
│   ├── sorts.hpp                  # Declarações dos 8 algoritmos de ordenação
│   ├── timer.hpp                  # Funções de medição de tempo
│   └── vector.hpp                 # Geração e cópia de vetores de teste
├── src/
│   ├── main.cpp                   # Execução dos benchmarks
│   ├── sorts.cpp                  # Implementação dos algoritmos
│   ├── timer.cpp                  # Implementação do temporizador
│   └── vector.cpp                 # Implementação dos geradores de vetor
├── Makefile
├── LICENSE
└── README.md
```

## Pré-requisitos
> - Compilador C++ (g++) com suporte para C++23
> - Make (mingw32-make no Windows ou make no Linux)

### Instalação no Windows
> Instale o MinGW-w64 (recomendado via WinLibs pelo winget, ou via MSYS2):
```powershell
winget install -e --id BrechtSanders.WinLibs.POSIX.UCRT
```
> Após instalar, reinicie o terminal para que o PATH seja atualizado.
> Para verificar se foi instalado corretamente, execute este comando no PowerShell:
```powershell
g++ --version
```

### Instalação no Linux
> Instale o g++ e o make usando o gerenciador de pacotes da sua distribuição:
> - Ubuntu / Debian / Mint: sudo apt update && sudo apt install build-essential
> - Fedora: sudo dnf install gcc-c++ make
> - Arch / Manjaro: sudo pacman -S base-devel

> Para verificar se foi instalado corretamente, execute este comando no Terminal:
```bash
g++ --version
```

## Como executar o trabalho
### Windows
> Na pasta raiz do projeto, execute no powershell:
```powershell
mingw32-make run      # Compila e executa
mingw32-make          # Apenas compila (gera build/programa.exe)
mingw32-make clean    # Remove a pasta build/
```

### Linux
> Na pasta raiz do projeto, execute no terminal:
```bash
make run              # Compila e executa
make                  # Apenas compila (gera build/programa)
make clean            # Remove a pasta build/
```