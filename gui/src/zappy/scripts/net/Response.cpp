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
    if (name == "WELCOME")
        return Response::type::RESPONSE_WELCOME;
    if (name == "MAGIC_GUI_OK")
        return Response::type::RESPONSE_MAGIC_GUI;
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
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    bool first_token = true;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        if (first_token) {
            first_token = false;
            m_type = match_type(token); 
            if (m_type == Response::type::RESPONSE_ERROR) {
                std::cerr << "Response unkown: \"" << token << "\"" << std::endl;
            }
        } else {
            m_args.push_back(token);
        }
        std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    if (s.size() > 0) {
        if (first_token) {
            m_type = match_type(s); 
            if (m_type == Response::type::RESPONSE_ERROR) {
                std::cerr << "Response unkown: \"" << s << "\"" << std::endl;
            }
        } else {
            m_args.push_back(s);
        }
    }
}