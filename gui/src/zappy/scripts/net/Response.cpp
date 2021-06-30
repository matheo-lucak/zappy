/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Response
*/

#include <iostream>
#include <string.h>

#include "Response.hpp"

static Response::type match_type(const std::string &name)
{
    if (name == "msz")
        return Response::type::RESPONSE_MSZ;
    if (name == "bct")
        return Response::type::RESPONSE_BCT;
    if (name == "tna")
        return Response::type::RESPONSE_TNA;
    if (name == "ppo")
        return Response::type::RESPONSE_PPO;
    if (name == "pst")
        return Response::type::RESPONSE_PST;
    if (name == "pnw")
        return Response::type::RESPONSE_PNW;
    if (name == "pex")
        return Response::type::RESPONSE_PEX;
    if (name == "pbc")
        return Response::type::RESPONSE_PBC;
    if (name == "pic")
        return Response::type::RESPONSE_PIC;
    if (name == "pie")
        return Response::type::RESPONSE_PIE;
    if (name == "enw")
        return Response::type::RESPONSE_ENW;
    if (name == "eht")
        return Response::type::RESPONSE_EHT;
    if (name == "ebo")
        return Response::type::RESPONSE_EBO;
    if (name == "edi")
        return Response::type::RESPONSE_EDI;
    if (name == "pdr")
        return Response::type::RESPONSE_PDR;
    if (name == "pgt")
        return Response::type::RESPONSE_PGT;
    if (name == "pdi")
        return Response::type::RESPONSE_PDI;
    if (name == "sgt")
        return Response::type::RESPONSE_SGT;
    if (name == "seg")
        return Response::type::RESPONSE_SEG;
    return Response::type::RESPONSE_ERROR;
}

Response::Response(std::string s)
{
    constexpr char delimiter[] = " \t";
    const std::size_t delim_len = strlen(delimiter);
    bool first_token = true;
    size_t pos_start = 0;
    size_t pos_end = 0;
    std::string token;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);

        if (first_token) {
            m_type = match_type(token); 
            if (m_type == Response::type::RESPONSE_ERROR) {
                std::cerr << "Response unkown: \"" << token << "\"" << std::endl;
            }
        } else {
            m_args.push_back(token);
        }

        pos_start = pos_end + delim_len;
        first_token = false;
        m_args.push_back(token);
    }
    m_args.push_back(s.substr(pos_start));
}