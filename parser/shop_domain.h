
#pragma once

#include "Domain.h"

namespace parser { namespace shop {

class ShopDomain : public Domain {

public:

	TokenStruct< HTNMethod * > htnMtds;// shop methods
	TokenStruct< HTNOperator * > htnOps;// shop operators
	

	ShopDomain() : Domain() {}

	ShopDomain( const std::string& s ) : ShopDomain() {
		parse(s);
	}

	~ShopDomain() {
		for ( unsigned i = 0; i < htnMtds.size(); ++i )
			delete htnMtds[i];
		for ( unsigned i = 0; i < htnOps.size(); ++i )
			delete htnOps[i];
	}

	void parse( const std::string & s ) override {
		Filereader f( s );

	    name = f.parseHTNDomainName( );

		if ( DOMAIN_DEBUG ) std::cout << name << "\n";

		for ( ; f.getChar() != ')'; f.next() ) {
			f.assert( "(" );
			f.assert( ":" );
			std::string t = f.getToken();

			if ( DOMAIN_DEBUG ) std::cout << t << "\n";

			if ( t == "OPERATOR" ) parseOperator( f );
		    else if ( t == "METHOD" ) parseMethod( f );
			else f.tokenExit( t );
		}
	}
	
	void parseMethod( Filereader & f ) {
		f.next();
		f.assert( "(" );
		HTNMethod * o = 0;
		o = new HTNMethod( f.getToken() );
		o->SHOPparse( f, types[0]->constants, *this );

		if ( DOMAIN_DEBUG ) std::cout << o << "\n";
		htnMtds.insert( o );
	}
	
	void parseOperator( Filereader & f ) {
		f.next();
		f.assert( "(" );
		HTNOperator * o = 0;
		o = new HTNOperator( f.getToken() );
		o->SHOPparse( f, types[0]->constants, *this );

		if ( DOMAIN_DEBUG ) std::cout << o << "\n";
		htnOps.insert( o );
	}	
	

	// Print the domain in SHOP format
	std::ostream& print(std::ostream& os) const override {
		os << "( DEFDOMAIN " << name << " (\n";

		 for ( unsigned i = 0; i < htnOps.size(); ++i ){
			htnOps[i]->SHOPPrint( os, 0, TokenStruct< std::string >(), *this );
		 }

		 for ( unsigned i = 0; i < htnMtds.size(); ++i )
			htnMtds[i]->SHOPPrint( os, 0, TokenStruct< std::string >(), *this );

		os << ")\n";
		return os;
	}
	
};

} } // namespaces
