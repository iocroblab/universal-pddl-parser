
#pragma once

#include "Ground.h"
#include "Condition.h"
#include "Function.h"
#include "Expression.h"


namespace parser { namespace pddl {

class Increase : public Condition {

public:

	Ground * incrementedGround;  // if null -> total-cost
	Expression * incrementExpr;  // the expression by which we increment

	Increase( int val = 1 );

	Increase( Function * f, const IntVec & p = IntVec() );

	Increase( const Increase * i, Domain & d );

	~Increase() {
		if ( incrementedGround ) delete incrementedGround;
		if ( incrementExpr ) delete incrementExpr;
	}

	void print( std::ostream & s ) const {
		s << "Increase ";
		if ( incrementedGround ) incrementedGround->print( s );
		if ( incrementExpr ) incrementExpr->print( s );
		s << "\n";
	}

	void PDDLPrint( std::ostream & s, unsigned indent, const TokenStruct< std::string > & ts, const Domain & d ) const override;

	void parse( Filereader & f, TokenStruct< std::string > & ts, Domain & d );

	void addParams( int m, unsigned n ) {}

	Condition * copy( Domain & d ) {
		return new Increase( this, d );
	}

};

} } // namespaces
