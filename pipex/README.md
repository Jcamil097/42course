# pipex

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/pipexe.png" alt="Pipex 42 project badge"/>
</p>

Pipex reproduce el comportamiento del | comando shell pipe en C.

Leemos desde infile, ejecutamos cmd1 con infile como entrada, enviamos la salida a cmd2, que escribirá en outfile. El resultado es prácticamente idéntico a este tipo de comando de shell:
```
$ < infile cmd1 | cmd2 > outfile file
```

## Compilar
Para compilar, usar ```make```, ```make all``` or ```make bonus```.

### Ejecucion regular de pipex
Pipex puede manejar 2 comandos. Ejecutar:

```
$ ./pipex input_file command1 command2 output_file
```
La salida se escribirá en el archivo de salida especificado. Si el archivo de salida existe, se sobrescribirá. Esto replica el comando de shell:
```
$ < input_file command1 | command2 > output_file
```

A cada comando se le pueden dar argumentos y opciones si están entre comillas. Por ejemplo:
```
$ ./pipex example.txt "cat" "grep x" "sed s/l/.../g" outfile.txt
```

### Ejecucion bonus de pipex
Pipex puede manejar 2 o mas comandos. Ejecutar:

```
$ ./pipex input_file command1 command2 ... commandn output_file
```
La salida se escribirá en el archivo de salida especificado. Si el archivo de salida existe, se sobrescribirá. Esto replica el comando de shell:
```
$ < input_file command1 | command2 | ... | commandn > output_file
```

A cada comando se le pueden dar argumentos y opciones si están entre comillas. Por ejemplo:
```
$ ./pipex example.txt "cat" "grep x" "sed s/l/.../g" outfile.txt
```

### Ejecución de pipex heredoc
También puede ejecutar pipex con un heredoc, como este:
```
$ ./pipex heredoc LIMITER command1 command2 ... commandn output_file
```
Luego se le pedirá que ingrese texto que se usará como entrada para los comandos. En este caso, el archivo de salida especificado no se sobrescribirá sino que se agregará, lo que replica el comportamiento del comando de shell:
```
$ << LIMITER command1 | command2 | ... | commandn >> output_file
```
