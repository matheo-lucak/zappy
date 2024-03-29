/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** run
*/

#include <unistd.h>
#include <time.h>
#include <signal.h>

#include "server/server.h"

static bool *global_run()
{
    static bool global = true;

    return &global;
}

static void sigint_handler(int __attribute__((unused))signum)
{
    *global_run() = false;
}

static void get_next_server_tick(server_t *s)
{
    static bool first_tick = true;
    static struct timespec last_time;
    struct timespec current_time;
    long delta_time_us;
    long time_for_tick_us;

    if (first_tick) {
        timespec_get(&last_time, TIME_UTC);
        first_tick = false;
        return;
    }
    timespec_get(&current_time, TIME_UTC);
    delta_time_us = (current_time.tv_nsec - last_time.tv_nsec) / 1000;
    time_for_tick_us = (long)(1000000 / s->freq) - delta_time_us;
    time_for_tick_us = time_for_tick_us >= 0 ? time_for_tick_us : 0;
    usleep(time_for_tick_us);
    last_time = current_time;
}

int server_run(server_t *s)
{
    s->status = SERVER_SUCCESS;
    s->is_running = true;
    *global_run() = true;
    signal(SIGINT, &sigint_handler);
    while (s->is_running && s->status == SERVER_SUCCESS && *global_run()) {
        get_next_server_tick(s);
        network_handle_clients_in(s);
        server_handle_request_parsing(s);
        server_handle_request(s);
        simulation_handle(s);
        network_handle_clients_out(s);
        server_clear_clients(s);
    }
    return s->status;
}
