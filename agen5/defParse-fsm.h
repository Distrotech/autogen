/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (defParse-fsm.h)
 *
 *  It has been AutoGen-ed  November 13, 2013 at 07:04:42 PM by AutoGen 5.18.1
 *  From the definitions    defParse.def
 *  and the template file   fsm
 *
 *  Automated Finite State Machine
 *
 *  Copyright (C) 1992-2013 Bruce Korb - all rights reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name ``Bruce Korb'' nor the name of any other
 *    contributor may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * AutoFSM IS PROVIDED BY Bruce Korb ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Bruce Korb OR ANY OTHER CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  This file enumerates the states and transition events for a FSM.
 *
 *  te_dp_state
 *      The available states.  FSS_INIT is always defined to be zero
 *      and FSS_INVALID and FSS_DONE are always made the last entries.
 *
 *  te_dp_event
 *      The transition events.  These enumerate the event values used
 *      to select the next state from the current state.
 *      DP_EV_INVALID is always defined at the end.
 */
#ifndef AUTOFSM_DEFPARSE_FSM_H_GUARD
#define AUTOFSM_DEFPARSE_FSM_H_GUARD 1
/**
 *  Finite State machine States
 *
 *  Count of non-terminal states.  The generated states INVALID and DONE
 *  are terminal, but INIT is not  :-).
 */
#define DP_STATE_CT  11
typedef enum {
    DP_ST_INIT,       DP_ST_NEED_DEF,   DP_ST_NEED_TPL,   DP_ST_NEED_SEMI,
    DP_ST_NEED_NAME,  DP_ST_HAVE_NAME,  DP_ST_NEED_VALUE, DP_ST_NEED_IDX,
    DP_ST_NEED_CBKT,  DP_ST_INDX_NAME,  DP_ST_HAVE_VALUE, DP_ST_INVALID,
    DP_ST_DONE
} te_dp_state;

/**
 *  Finite State machine transition Events.
 *
 *  Count of the valid transition events
 */
#define DP_EVENT_CT 16
typedef enum {
    DP_EV_AUTOGEN,       DP_EV_DEFINITIONS,   DP_EV_END,
    DP_EV_VAR_NAME,      DP_EV_OTHER_NAME,    DP_EV_STRING,
    DP_EV_HERE_STRING,   DP_EV_DELETE_ENT,    DP_EV_NUMBER,
    DP_EV_LIT_SEMI,      DP_EV_LIT_EQ,        DP_EV_LIT_COMMA,
    DP_EV_LIT_O_BRACE,   DP_EV_LIT_C_BRACE,   DP_EV_LIT_OPEN_BKT,
    DP_EV_LIT_CLOSE_BKT, DP_EV_INVALID
} te_dp_event;

/**
 *  Run the FSM.  Will return DP_ST_DONE or DP_ST_INVALID
 */
extern te_dp_state
dp_run_fsm( void );

#endif /* AUTOFSM_DEFPARSE_FSM_H_GUARD */
/*
 * Local Variables:
 * mode: C
 * c-file-style: "stroustrup"
 * indent-tabs-mode: nil
 * End:
 * end of defParse-fsm.h */
