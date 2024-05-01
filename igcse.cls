\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{igcse}[2024/05/01 Document class that looks like an IGCSE question paper]


\LoadClass[11pt, a4paper, addpoints]{exam}
\RequirePackage{changepage}
\RequirePackage{ifthen}

% CUSTOM DEFINITIONS - SKIP TO "BEGIN QUESTIONS"
% \newcommand{\esubjectcode}{0470}
% \newcommand{\esubjectname}{HISTORY}
% \newcommand{\ecomponentcode}{01}
% \newcommand{\ecomponentname}{Paper 1 Structured Questions}
% \newcommand{\emonthshort}{M/J}
% \newcommand{\emonthlong}{May/June}
% \newcommand{\eyear}{24}
% \newcommand{\etime}{2 hours}
% \newcommand{\etotalmark}{60}
% \newcommand{\eqlistmargin}{0em}
% \newcommand{\eyouwillneed}{
% 	You will need:\quad Answer booklet (enclosed)
% }
% \newcommand{\einstructions}{
% 	\textbf{INSTRUCTIONS}
% 	\begin{itemize}
% 		\setlength{\parskip}{0ex}
% 		\item Answer \textbf{three} question:\\
% 			\mbox{}\quad answer \textbf{two} questions from section A\\
% 			\mbox{}\quad answer \textbf{one} question from section B
% 	\end{itemize}
% }
% \newcommand{\einformation}{
% 	\textbf{INFORMATION}
% 	\begin{itemize}
% 		\setlength{\parskip}{0ex}
% 		\item The total mark for this paper is \textbf{\etotalmark}.
% 		\item All questions are worth equal marks.
% 	\end{itemize}
% }

% FONTS
\RequirePackage{iftex}
\iftutex
	\RequirePackage{fontspec}
	\setmainfont{Times New Roman}
	\setsansfont{Arial}
	\setmonofont{Courier New}
	\RequirePackage{unicode-math}
	\setmathfont{Times New Roman}
\else
	\RequirePackage{tgtermes}
	\RequirePackage{tgheros}
	\RequirePackage{tgcursor}
\fi
\renewcommand{\familydefault}{\sfdefault}

% PAGE LAYOUT
\RequirePackage[a4paper, left=0.8in, right=0.8in, top=0.6in, bottom=0.6in]{geometry}
\extrafootheight{.4in}
\extraheadheight{.3in}

% HEADERS AND FOOTERS
\pagestyle{headandfoot}
\firstpageheader{}{}{}
\runningheader{}{\textbf{\thepage}}{}
\firstpagefooter{\footnotesize{YKPS 20\eyear}}{}{\textbf{\protect {[}Turn over}}
\runningfooter{\footnotesize{YKPS 20\eyear}}{\footnotesize \esubjectcode/\ecomponentcode/\emonthshort/\eyear}{\oddeven{\textbf{\protect {[}Turn over}}{\phantom{\textbf{\protect {[}Turn over}}}}

% TEXT FORMATTING
\RequirePackage{indentfirst}
\setlength{\parindent}{0pt}
\setlength{\parskip}{\smallskipamount}

% LISTS
\RequirePackage{enumitem}
\setlist[itemize]{wide=0pt,itemsep=0ex,leftmargin=1em,align=left,labelwidth=1em,labelsep=0em,topsep=0em,parsep=\medskipamount,label=\textbullet}

% EXAM DOCUMENT SETTINGS
\noprintanswers
\pointsinrightmargin
\bracketedpoints
\marksnotpoints
\pointsdroppedatright % Basically don't display marks at all
\totalformat{[Total: \totalpoints]}
\unframedsolutions

% QUESTION FORMATS
\renewcommand{\questionlabel}{\textbf{\thequestion}}
\renewcommand{\partlabel}{\textbf{(\thepartno)}}
\renewcommand{\subpartlabel}{\textbf{(\thesubpart)}}
\renewcommand{\subsubpartlabel}{\textbf{\thesubsubpart)}}
\renewcommand{\choicelabel}{\textbf{\thechoice}}
\renewcommand{\solutiontitle}{}
\renewcommand{\questionshook}{%
	\addtolength{\leftmargin}{\eqlistmargin}%
	\setlength{\labelsep}{0em}%
	\setlength{\parsep}{\bigskipamount}
	\setlength{\itemsep}{\bigskipamount}
	\renewcommand\makelabel[1]{\llap{##1}\hss}
}
\renewcommand{\choiceshook}{%
	\setlength{\leftmargin}{0pt}%
	\setlength{\labelsep}{2em}%
	\setlength{\labelwidth}{-\labelsep}
	\renewcommand\makelabel[1]{\llap{##1}\hss}
}
\renewcommand{\partshook}{%
	%\addtolength{\leftmargin}{1.5pt}%
	%\setlength{\labelsep}{1em}%
	\setlength{\parsep}{\bigskipamount}
	\renewcommand\makelabel[1]{\llap{##1}\hss}
}

% LITERATURE EXAM SPECIAL QUOTATION SETTINGS
\makeatletter
\let\oeqt\endquotation
\newlength{\nosepsep}
\setlength{\nosepsep}{-2em}
\renewenvironment{quotation}{\list{}{\listparindent 1.5em\itemindent\listparindent\rightmargin\leftmargin\parsep\z@\@plus\p@}\item\relax}{\oeqt}
\makeatother
% \renewcommand\makelabel[1]{\bfseries\llap{Either\quad #1}\hss}

% ADDITIONAL PACKAGES
\RequirePackage[version=4]{mhchem}
\RequirePackage{amsmath}
\RequirePackage{amssymb}
\RequirePackage{xcolor}
\RequirePackage{multicol}
\RequirePackage{lscape}
\RequirePackage{blindtext}
\RequirePackage{graphicx}
\RequirePackage{array}
\RequirePackage{subcaption}

% CONVENIENT MACROS
\newcommand\accept{\textbf{accept} }
\newcommand\reject{\textbf{reject} }

% LAYOUT MACROS
\RequirePackage{refcount,xparse}
\newcommand{\blankpage}{\newpage\mbox{}\hfill\textbf{BLANK PAGE}\hfill\mbox{}\par}
\newcommand{\nomoreturnovers}{\runningfooter{\footnotesize{YKPS 20\eyear}}{\footnotesize \esubjectcode/\ecomponentcode/\emonthshort/\eyear}{\phantom{\textbf{\protect {[}Turn over}}}}
\ExplSyntaxOn
\NewDocumentCommand{\ensurefour} { }
	{
		\label{pagebeforefour}
		\prg_replicate:nn
		{ \int_mod:nn { 4 - \int_mod:nn { \getpagerefnumber{pagebeforefour} } { 4 } } { 4 } }
		{ \blankpage }
	}
\ExplSyntaxOff
% \AtEndDocument{\par\nomoreturnovers\ensurefour}

\newcommand{\coverpage}{
	\begingroup
		\includegraphics[height=8ex]{/home/runxiyu/misc/ykps-bw-logo.pdf}\smallskip
	
	        \begin{minipage}{0.1175\textwidth}
	        CANDIDATE NAME
	        \end{minipage} 
	        \hfill
	        \fbox{
	                \begin{minipage}{0.81\textwidth}
	                        \mbox{}\hfill\vspace*{5.6ex}\mbox{}
	                \end{minipage}
	        }
			
		\smallskip\medskip\hrule\smallskip
		{
			\setlength{\parskip}{\medskipamount}
			\textbf{\esubjectname}\hfill\textbf{\esubjectcode/\ecomponentcode}\par
			\ecomponentname\hfill\textbf{\emonthlong{} 20\eyear}\par
			\mbox{}\hfill\textbf{\etime}\par
			\setlength{\parskip}{\smallskipamount}\par\eyouwillneed
		}\bigskip\hrule\medskip\par
		\einstructions\par\vspace*{1em}\einformation\par\vfill\par\hrule
		\begin{center}
			\vspace*{-2ex}
			This document has \textbf{\numpages} pages. Any blank pages are indicated.
		\end{center}
	\endgroup
	\newpage
	\setlength{\parskip}{\bigskipamount}
}
