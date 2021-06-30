/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Request
*/

#ifndef REQUEST_HPP_
#define REQUEST_HPP_

#include <string>

class Request
{
public:
    inline static const char *RQ_CONNECT            = "0xea83f3_gui_application\n";
    inline static const char *RQ_MAP_SIZE           = "msz\n";
    inline static const char *RQ_TILE_CONTENT       = "bct %d %d\n";
    inline static const char *RQ_MAP_CONTENT        = "mct\n";
    inline static const char *RQ_TEAM_NAMES         = "tna\n";
    inline static const char *RQ_PLAYER_POSITION    = "ppo %d\n";
    inline static const char *RQ_PLAYER_STATS       = "pst %d\n";
    inline static const char *RQ_TIME_UNIT_REQUEST  = "sgt\n";

public:
    Request(const char *format, ...);
    ~Request() = default;

    bool        is_valid;
    std::string data;
};

#endif /* !REQUEST_HPP_ */
