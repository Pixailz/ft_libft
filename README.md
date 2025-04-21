# libft

[![CI](https://github.com/Pixailz/ft_libft/actions/workflows/CI.yml/badge.svg)](https://github.com/Pixailz/ft_libft/actions/workflows/CI.yml)

## TODO

1. improve ft_printf
   1. finish flags and padding for all types
1. error
   1. implement errno
1. doc
   1. update usage / help

## Implemented RFC

1. Internet Protocol ([RFC791](https://datatracker.ietf.org/doc/html/rfc791))
   - t_iphdr
1. Internet Control Message Protocol ([RFC792](https://datatracker.ietf.org/doc/html/rfc792))
   - t_icmphdr_echo
   - t_icmphdr_time_exceed
1. User Datagram Protocol ([RFC768](https://datatracker.ietf.org/doc/html/rfc768))
   - t_udphdr
1. Domain Names ([RFC1035](https://datatracker.ietf.org/doc/html/rfc1035))
   - t_dnshdr
1. ELF binary format (https://refspecs.linuxfoundation.org/elf/gabi4+/ch4.eheader.html)
   - t_elfbin
   - t_e_hdr
   - t_h_hdr
   - t_sym

## Usage

```bash
make clean
make fclean
make re
make help
make <part>
make <part1|part2 ... partN>
```

> do `make help` to have a short summary of all part

- available part are:
	- integer
	- string
	- memory
	- check
	- list
	- print
	- input
	- random
	- linux
	- parsing
	- network
    	- ipv4
    	- packet
  	- sort
  	- binary
    	- elf
