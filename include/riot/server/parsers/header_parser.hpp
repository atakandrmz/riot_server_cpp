/**
 * @author Canberk Sönmez
 * 
 * @date Thu Jul  5 23:29:13 +03 2018
 * 
 */

#ifndef RIOT_SERVER_HEADER_PARSER_INCLUDED
#define RIOT_SERVER_HEADER_PARSER_INCLUDED

#include <list>
#include <utility>
#include <map>
#include <sstream>
#include <boost/spirit/home/x3.hpp>

namespace riot::server {
    namespace header_parser {
        namespace x3 = boost::spirit::x3;
        
        using entry = std::list<std::string>;
        
        namespace grammar {
            using x3::space;
            using x3::lexeme;
            using x3::char_;
            
            struct entry_class;
            struct values_class;
            struct identifier_class;
            
            static const x3::rule<entry_class, entry>
                entry("entry");
            static const x3::rule<values_class, std::list<std::string>>
                values("values");
            static const x3::rule<identifier_class, std::string>
                identifier("identifier");
            
            static auto const entry_def =
                lexeme[identifier >> ':'] >> values;
            
            static auto const values_def =
                +identifier;
            
            static auto const identifier_def =
                lexeme[+char_("a-zA-Z0-9_")];
            
            BOOST_SPIRIT_DEFINE(
                entry,
                values,
                identifier);
        }
        
        static auto const entry_ = grammar::entry;
        
        template <typename ConstIt>
        inline auto parse(
            ConstIt const begin, ConstIt const end) {
            auto it = begin;
            entry e;
            bool r = false;
            try {
                r = x3::phrase_parse(
                    it,
                    end,
                    entry_,
                    x3::space,
                    e);
            }
            catch (std::exception const &ex) {
                std::ostringstream oss;
                oss << "[parse_header] unexpected throw at " << (it-begin)
                    << " error message: " << ex.what();
                throw std::runtime_error(oss.str());
            }
            if (!r)
                throw std::runtime_error(
                    "[parse_header] parser error at " +
                    std::to_string(it-begin));
            if (it != end)
                throw std::runtime_error(
                    "[parse_header] not consumed at " +
                    std::to_string(it-begin));
            return e;
        }
        
        template <typename String>
        inline auto parse(const String &str) {
            return parse(std::cbegin(str), std::cend(str));
        }
    }
}

#endif // RIOT_SERVER_HEADER_PARSER_INCLUDED
