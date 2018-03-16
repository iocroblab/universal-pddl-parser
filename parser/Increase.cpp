
#include "Domain.h"

namespace parser { namespace pddl {

Increase::Increase( int val )
	: incrementedGround( 0 ), incrementExpr( new ValueExpression( val ) ) {}

Increase::Increase( Function * f, const IntVec & p ) {
	incrementExpr = new FunctionExpression( new Ground( f, p ) );
}

Increase::Increase( const Increase * i, Domain & d ) {
	if ( i->incrementedGround ) {
		incrementedGround = dynamic_cast< Ground * >( i->incrementedGround->copy( d ) );
	}

	if ( i->incrementExpr ) {
		incrementExpr = dynamic_cast< Expression * >( i->incrementExpr->copy( d ) );
	}
}

void Increase::PDDLPrint( std::ostream & s, unsigned indent, const TokenStruct< std::string > & ts, const Domain & d ) const {
	tabindent( s, indent );
	s << "( INCREASE ";

	if ( incrementedGround ) {
		incrementedGround->PDDLPrint( s, 0, ts, d );
	}
	else {
		s << " ( TOTAL-COST )";
	}

	s << " ";
	incrementExpr->PDDLPrint( s, 0, ts, d );

	s << " )";
}

void Increase::parse( Filereader & f, TokenStruct< std::string > & ts, Domain & d ) {
	f.next();

	f.assert_token( "(" );

	std::string increasedFunction = f.getToken();
	if ( increasedFunction == "TOTAL-COST" ) {
		f.assert_token( ")" );
	}
	else {
		incrementedGround = new Ground( d.funcs.get( increasedFunction ) );
		incrementedGround->parse( f, ts, d );
	}

	f.next();

	incrementExpr = createExpression( f, ts, d );

	f.next();
	f.assert_token( ")" );
}

} } // namespaces
