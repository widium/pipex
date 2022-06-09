# File Descriptor
![](https://i.imgur.com/EAfRIKV.png)
![](https://i.imgur.com/B0yUwET.png)
![](https://i.imgur.com/Q5shjxh.png)
***
# Process
![](https://i.imgur.com/4ModqSs.png)
![](https://i.imgur.com/uERCVr5.png)
![](https://i.imgur.com/eOfpd7t.png)
![](https://i.imgur.com/vZiCfpd.png)
***
# Redirection et Pipe
![](https://i.imgur.com/qYNcbVJ.png)
![](https://i.imgur.com/P77jLAh.png)
***
# Recupereration de tous les PATH
~~~C
int main(int argc, char **argv, char **env)
{
    int i = -1;
    while (env[++i]) 
            printf("%s\n",ft_strnstr(env[i], "PATH", ft_strlen(env[i])));
}
>>>
PATH=/home/widium/.local/bin:/usr/condabin:/usr/local/sbin:/usr  
/local/bin:/usr/bin:/usr/lib/jvm/default/bin:/usr/bin/site_perl  
:/usr/bin/vendor_perl:/usr/bin/core_perl:/var/lib/snapd/snap/bi  
n
~~~
***
# Access() command - Tester l'existance et les permissions des fichiers
- **Si le Fichier Exsite** : `F_OK`
- **Les permissions du Fichier** : 
	- `R_OK` pour la **lecture**
	- `W_OK` pour l'**ecriture** 
	- `X_OK` pour l'**execution**
***
### Tester avec un executable :
- Donner le path de l'executable
- **Checker si le Fichier existe et toutes les Permissions**
- Checker l'erreur avec perror()
~~~C
int main(int argc, char **argv, char **env)
{
    int fd = access("/bin/ls", R_OK & W_OK & X_OK & F_OK);
    printf("%d\n",fd);
    perror("Error description : ");
}
>>>
0
"Error description : : Success"
~~~
***
# Executer un binaire en C
~~~C
execve(char *"PATH", char **"FLAGS", env)
~~~
***
### La commande `execve()` , test avec `ls`
~~~C
int main(int argc, char **argv, char **env)
{
    execve("/bin/ls", argv, env);
}
~~~

~~~bash
$ ./a.out -la

>>>
rwxr-xr-x 4 widium widium  4096 23 mai   17:22 .
drwxr-xr-x 8 widium widium  4096 23 mai   09:48 ..
drwxr-xr-x 8 widium widium  4096 23 mai   16:21 .git
......
~~~
***
# Pratique
## Pipex Simple 
![](https://i.imgur.com/h5WCbDe.png)

## Multi-Pipex
### Parsing Chained-list
![](https://i.imgur.com/cyLgikt.png)
### Multi-Pipe mobile
![](https://i.imgur.com/9rzCnjY.png)
![](https://i.imgur.com/100dRX2.png)
![](https://i.imgur.com/SBYN3o1.png)
### Main
![](https://i.imgur.com/6MsMr0a.png)

![](https://i.imgur.com/a3L8IbG.png)

## Here_doc
![](https://i.imgur.com/4a0FuKZ.png)
![](https://i.imgur.com/MBMm2Os.png)
