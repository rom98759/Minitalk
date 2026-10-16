# Minitalk

**Communication entre deux processus via les signaux UNIX.** Un client transmet
une chaîne à un serveur **bit par bit**, en n'utilisant que `SIGUSR1` et
`SIGUSR2` — aucune socket, aucun fichier partagé. Projet du tronc commun de
l'École 42.

![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Signals](https://img.shields.io/badge/UNIX-signals-1a1a1a?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-1a1a1a?style=flat-square)

## Principe

```mermaid
sequenceDiagram
    participant C as client
    participant S as server (PID)
    Note over S: affiche son PID au démarrage
    loop pour chaque bit de chaque caractère
        C->>S: SIGUSR1 (bit = 1) ou SIGUSR2 (bit = 0)
        S-->>C: accusé de réception
    end
    Note over S: recompose les octets et affiche le message
```

Chaque caractère est envoyé bit par bit ; le serveur reconstruit les octets et,
au caractère nul, affiche le message complet. Le serveur accuse réception de
chaque bit pour fiabiliser la transmission.

## Build & lancement

```bash
make                       # compile -> ./server et ./client
./server                   # affiche son PID, ex. 4242
./client 4242 "Hello 42!"  # envoie le message au serveur
```

## Structure

```
server.c        boucle de réception, reconstruction des octets
server_utils.c  handlers de signaux
client.c        découpe le message en bits et les émet
```

Compilé avec `-Wall -Wextra -Werror` (norme 42).

## Licence

MIT — voir [LICENSE](LICENSE).
