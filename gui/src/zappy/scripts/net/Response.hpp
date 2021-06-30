/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Response
*/

#ifndef RESPONSE_HPP_
#define RESPONSE_HPP_

#include <string>
#include <list>

class Response {
public:
enum type
{
    RESPONSE_ERROR,
    RESPONSE_MAGIC_GUI, // "MAGIC_GUI_OK\n"
    RESPONSE_MSZ, // "msz %d %d\n"
    RESPONSE_BCT, // "bct %d %d %d %d %d %d %d %d %d\n"
    RESPONSE_TNA, // "tna %s\n"
    RESPONSE_PPO, // "ppo %d %d %d %d\n"
    RESPONSE_PST, // "pst %d %d %d %d %d %d %d %d\n"
    RESPONSE_PNW, // "pnw %d %d %d %d %d %s\n"
    RESPONSE_PEX, // "pex %d\n"
    RESPONSE_PBC, // "pbc %d %s\n"
    RESPONSE_PIC, // "pic %d %d %d %d %d %d %d %d %d %d\n"
    RESPONSE_PIE, // "pie %d %d %d\n"
    RESPONSE_ENW, // "enw %d %d %d %d\n"
    RESPONSE_EHT, // "eht %d\n"
    RESPONSE_EBO, // "ebo %d %d %d %d %d %s\n"
    RESPONSE_EDI, // "edi %d\n"
    RESPONSE_PDR, // "pdr %d %d\n"
    RESPONSE_PGT, // "pgt %d %d\n"
    RESPONSE_PDI, // "pdi %d\n"
    RESPONSE_SGT, // "sgt %d\n"
    RESPONSE_SEG, // "seg %s\n"
};
    Response(std::string s);
    ~Response() = default;

    bool                    m_is_valid;
    type                    m_type;
    std::list<std::string>  m_args;
};

#endif /* !RESPONSE_HPP_ */
